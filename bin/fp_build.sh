#!/bin/bash

# error handling
if ! command -v jq &> /dev/null
then
    echo "jq is a dependency, and could not be found, see https://stedolan.github.io/jq for installation details"
    exit
fi

Help()
{
	echo "Usage: $0 -k <keyboard> -m <keymap> -c <convert_to controller> -r -h"
	echo ""
	echo "  -k keyboard directory (optional, default is all fingerpunch keyboards)"
	echo "  -m keymap (optional, defaults to the 'default' keymap)"
	echo "  -c add CONVERT_TO parameter for a controller (eg -c stemcell)"
    echo "  -i (interactive mode, take feature selection user input to generate build command)"
	echo "  -r (run the build command(s), defaults to outputting the build string)"
	echo "  -h (show this dialog)"
	echo ""
	echo "Examples: "
	echo "--------"
	echo "fp_build.sh -i -k \"rockon/v2\" -m sadekbaroudi -r"
	echo "fp_build.sh -i -m sadekbaroudi"
	echo "fp_build.sh -k \"barobord\""
}

get_valid_keyboards() {
	valid_keyboards=""
	directories=$(find ${1}/* -maxdepth 0 -type d)
	echo "${directories}" | while read line; do
		if [[ -e "${line}/fp_build.json" ]]; then
		    echo -n "${line} "
		fi
		for i in {1..9}
		do
			if [[ -e "${line}/v${i}/fp_build.json" ]]; then
			    echo -n "${line}/v${i} "
			fi
		done
	done
}

build_keyboard_user_input() {
	local build_json="${1}/fp_build.json"
	local keyboard_base_dir="${1}"
	local keyboard_name="${1#${2}/}"
	local run_build="${4}"

	local build_string="make ${keyboard_base_dir#keyboards\/}:${3}"
	echo "${build_string}"
	# get the total number of paramters
	top_level_element_count=$(cat "${build_json}" | jq 'length')
    # loop through each parameter
	for ((param_iter = 0 ; param_iter < top_level_element_count ; param_iter++)); do
        # get the parameter type to decide how to handle it
		param_type=$(cat "${build_json}" | jq -r ".[${param_iter}].type")

        # get the string to present to the user for their input
		user_input_string=$(cat "${build_json}" | jq -r ".[${param_iter}].user_input")

        # if it's a "one-of"... in other words, pick an option from a list
		if [[ "${param_type}" == "one-of" ]]; then
			options_count=$(cat "${build_json}" | jq ".[${param_iter}].names | length")
			user_input_string+=" (0-${options_count}): "

			echo -n "${user_input_string}"
			read user_choice
			while [[ $user_choice -lt 0 || $user_choice -gt $options_count ]]; do
				echo "Invalid choice: ${user_choice}"
				echo -n "${user_input_string}"
				read user_choice
			done

			# start at 1, because 0 should always be "none"
			param_names_counter=1
			param_names=$(cat "${build_json}" | jq -r ".[${param_iter}].names | @sh" | tr -d \')
			for param_name in $param_names; do
			    if [[ $param_names_counter -eq $user_choice ]]; then
			    	build_string+=" ${param_name}=yes"
			    fi
			    ((param_names_counter+=1))
			done
        # if it's a single value choice for a parmeter, or "yes or no" question
		elif [[ "${param_type}" == "single" ]]; then
			user_input_string+=" (yes/no): "

			echo -n "${user_input_string}"
			read user_choice

			while [[ $user_choice != "yes" && $user_choice != "no" && $user_choice != "y" && $user_choice != "n" ]]; do
				echo "Invalid choice: ${user_choice}"
				echo -n "${user_input_string}"
				read user_choice
			done

            if [[ "${user_choice}" == "y" ]]; then
                user_choice="yes"
            fi
            if [[ "${user_choice}" == "n" ]]; then
                user_choice="no"
            fi

			param_name=$(cat "${build_json}" | jq -r ".[${param_iter}].name")
			build_string+=" ${param_name}=${user_choice}"
		else
			echo "invalid type in json file: ${param_type}"
			exit
		fi
	done

	if [[ -n "${5}" && "${5}" != "no" ]]; then
		build_string+=" CONVERT_TO=${5}"
	fi

	process_build_string "${build_string}" "${run_build}"
}


build_keyboard_all_combinations() {
	local build_json="${1}/fp_build.json"
	local keyboard_base_dir="${1}"
	local keyboard_name="${1#${2}/}"
	local run_build="${4}"

	local build_string_base="make ${keyboard_base_dir#keyboards\/}:${3}"

	if [[ -n "${5}" && "${5}" != "no" ]]; then
		build_string_base+=" CONVERT_TO=${5}"
	fi

	make_build_string_recursive "${build_json}" "${run_build}" 0 "${build_string_base}"
}

# make_build_string_recursive "${build_json}" "${run_build}" "${param_number}" "${build_string_base}"
make_build_string_recursive() {
    local build_json="${1}"
	local run_build="${2}"
    local param_number=$3
    local build_string_base="${4}"
	local top_level_element_count=$(cat "${build_json}" | jq 'length')

	if [[ $((param_number)) -ge $((top_level_element_count)) ]]; then
		process_build_string "${build_string_base}" "${run_build}"
		return;
	fi

    local param_type=$(cat "${build_json}" | jq -r ".[${param_number}].type")
	local next_param_number=$((param_number + 1))

    # if it's a "one-of"... in other words, pick an option from a list
    if [[ "${param_type}" == "one-of" ]]; then
		param_names=$(cat "${build_json}" | jq -r ".[${param_number}].names | @sh" | tr -d \')
		for param_name in $param_names; do
			make_build_string_recursive "${build_json}" "${run_build}" $next_param_number "${build_string_base} ${param_name}=yes"
		done
    # if it's a single value choice for a parmeter, or "yes or no" question
    elif [[ "${param_type}" == "single" ]]; then
		param_name=$(cat "${build_json}" | jq -r ".[${param_number}].name")
		make_build_string_recursive "${build_json}" "${run_build}" $next_param_number "${build_string_base} ${param_name}=yes"
		make_build_string_recursive "${build_json}" "${run_build}" $next_param_number "${build_string_base} ${param_name}=no"
    else
        echo "invalid type in json file: ${param_type}"
        exit
    fi
}

# process_build_string $build_string $run_build
process_build_string() {
	build_string="$1"
	run_build="$2"

	echo "${build_string}"

	if [[ "${run_build}" == "yes" ]]; then
		echo "fp_build.sh: Running QMK Build...."
		echo ""
		eval "${build_string}"
	fi
}

Keyboard=""
Keymap="default"
RunBuild="no"
ConvertTo="no"
Interactive="no"
while getopts "k:m:c:rhi" option; do
    case $option in
        k) Keyboard=${OPTARG};;
        m) Keymap=${OPTARG};;
		c) ConvertTo=${OPTARG};;
		i) Interactive="yes";;
		r) RunBuild="yes";;
        h) Help
           exit;;
    esac
done

#### code starts here

# set up variables
FP_KB_DIR="keyboards/fingerpunch"
FP_KB=("${Keyboard}")
if [[ -z "${Keyboard}" ]]; then
	FP_KB=$(get_valid_keyboards "${FP_KB_DIR}")
else
	FP_KB=("${FP_KB_DIR}/${FP_KB}")
	if [[ ! -e "${FP_KB}" ]]; then
		echo "${FP_KB} is not a valid file, can't build"
		exit
	fi
fi;

for filename in $FP_KB; do
	if [[ "${Interactive}" == "yes" ]]; then
	    echo "Running for ${filename}"
    	build_keyboard_user_input "${filename}" "${FP_KB_DIR}" "${Keymap}" "${RunBuild}" "${ConvertTo}"
    else
        # build_keyboard_all_combinations "${filename}" "${FP_KB_DIR}" "${Keymap}" "${RunBuild}" "${ConvertTo}" "build string" "current param"
        build_keyboard_all_combinations "${filename}" "${FP_KB_DIR}" "${Keymap}" "${RunBuild}" "${ConvertTo}" ""
    fi
done