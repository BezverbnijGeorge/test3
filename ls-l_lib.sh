#!/bin/bash

# Виконання команди ls -l та збереження результату в змінній
files=$(ls -l /home/schmjul/)

# Створення масиву пар елементів з першого та останнього стовпця
pairs=()
while read -r line; do
  first_column=$(echo "$line" | awk '{print $1}')
  last_column=$(echo "$line" | awk '{print $NF}')
  pairs+=("$first_column $last_column")
done <<< "$files"

# Виведення пар елементів
for pair in "${pairs[@]}"; do
  echo "$pair"
done
