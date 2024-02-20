#!/bin/bash

# Prompt the user for input
read -p "Enter a file name (without extension): " filename

# Define the file extension
file_extension=".cpp"

# Concatenate the input with the file extension
full_filename="/${filename}${file_extension}"
current_path=$(pwd)

# Display the concatenated string

echo "path: $current_path"
echo "The full filename is: $full_filename"
full_path=${current_path}${full_filename}
output_file=${full_path%.*}
echo "fullpath is $full_path"
g++ -o ${output_file} ${full_path}


