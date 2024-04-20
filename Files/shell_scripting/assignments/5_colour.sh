#5. How to write script, that will print, Message ""Hello World"", in Bold and Blink effect, and in different Colors like red, brown etc using echo command."


#!/bin/bash

# ANSI escape codes for text formatting
BOLD='\033[1m'
BLINK='\033[5m'
RESET='\033[0m'

# Function to echo text with a specific color and formatting
print_colored_text() {
    local color="$1"
    local text="$2"
    echo -e "${BOLD}${BLINK}${color}${text}${RESET}"
}

# Input text
input_text="hello world"

# List of color codes for blinking text
colors=("31" "32" "34" "35" "36")

# Usage example
for color in "${colors[@]}"; do
    print_colored_text "\033[${color}m" "$input_text"
    sleep 1  # Adjust the sleep duration as needed
done
