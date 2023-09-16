#!/bin/bash

while true; do
    # Display the shell prompt
    echo -n "SimpleShell $ "

    # Read the user input
    read user_input

    # Check if the user wants to exit
    if [ "$user_input" = "exit" ]; then
        echo "Exiting SimpleShell."
        break
    fi

    # Iterate through directories in PATH
    IFS=":" read -ra path_dirs <<< "$PATH"
    command_found=0

    for dir in "${path_dirs[@]}"; do
        # Check if the command exists in the current directory
        if [ -x "$dir/$user_input" ]; then
            command_found=1
            # Execute the command in a new process
            "$dir/$user_input"
            break
        fi
    done

    # If the command was not found, display an error message
    if [ $command_found -eq 0 ]; then
        echo "SimpleShell: Command not found: $user_input"
    fi
done

