#!/bin/bash

# FILEPATH: /home/tlenovo/projects/study/42_push_swap/test.sh
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

PRINT_IO=true

# Loop through all files in the ./tests folder that contain the word "test"
for file in ./tests/*test*; do
	# Extract the numbers from the file
	numbers=$(cat "$file")

	# Execute the program "pushswap" with the numbers as arguments
	result=$(./pushswap $numbers)
	if [ $PRINT_IO = true ]; then
		echo "Input\t: $(echo "$numbers" | tr '\n' ' ')"
		echo "Output\t: $result"
	fi
	# Check if the list of numbers is in order from min to max
	for number in $(echo "$result" | tr ' ' '\n')
	do
		if [ -n $prev_number ]; then
			prev_number=$number
			continue 
		fi
		# Check if the current number is greater than the previous number
		if [ $number -lt $prev_number ]; then
			not_greater=$number
			break
		fi

		# Set the current number as the previous number for the next iteration
		prev_number=$number
	done

	if [ -n $not_greater ]; then 
		echo "$file:\t\t ${GREEN}OK${NC}"
	else
		echo "$file:\t\t ${RED}KO${NC}"
	fi

done
