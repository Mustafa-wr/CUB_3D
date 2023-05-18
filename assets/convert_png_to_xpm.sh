#!/bin/bash

# Check if ImageMagick is installed
if ! command -v convert &> /dev/null; then
    echo "ImageMagick is not installed. Please install it first."
    exit 1
fi

# Check if a filename is provided as an argument
if [ -z "$1" ]; then
    echo "Please provide the filename of the PNG image to convert."
    exit 1
fi

# Check if the file exists
if [ ! -f "$1" ]; then
    echo "File not found: $1"
    exit 1
fi

# Set output filename
output_file="${1%.*}.xpm"

# Convert PNG to XPM
convert "$1" "$output_file"

echo "Conversion complete. Output file: $output_file"

