#!/bin/sh

while read -r line; do
    if [ $(echo "$line" | grep -xcE "[a-zA-Z]+") -eq 1 ]; then
        echo "it is a word"
    elif [ $(echo "$line" | grep -xcE "[0-9]") -eq 1 ]; then
        echo "it is a digit"
    elif [ $(echo "$line" | grep -xcE "[0-9]{2,}") -eq 1 ]; then
        echo "it is a number"
    elif [ $(echo "$line" | grep -xcE "[ \t]+|^$") -eq 1 ]; then
        echo "it is empty"
    elif [ $(echo "$line" | grep -xcE "[a-zA-Z0-9]+") -eq 1 ]; then
        echo "it is an alphanum"
    else
        echo "it is too complicated"
        exit 0
    fi
done
