#!/bin/bash

# Remove all .txt files in the current directory
rm -f ./*.txt

# Iterate over each file matching the wildcard pattern
for file in ./df*; do
    # Check if the current file exists
    if [ -e "$file" ]; then
        # Execute your program for each matching file and append output to fifo.txt
        ../fifo "$file" >> fifo.txt
    fi
done

# Iterate over each file matching the wildcard pattern
for file in ./df*; do
    # Check if the current file exists
    if [ -e "$file" ]; then
        # Execute your program for each matching file and append output to sjf.txt
        ../sjf "$file" >> sjf.txt
    fi
done

# Iterate over each file matching the wildcard pattern
for file in ./df*; do
    # Check if the current file exists
    if [ -e "$file" ]; then
        for ((i = 10; i <= 100; i += 30)); do
            # Execute your program for each matching file and append output to rr_${i}.txt
            ../rr ${i} "$file" >> "rr_${i}.txt"
        done
    fi
done