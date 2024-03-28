#!/bin/sh

if [ $# -ne 2 ]; then
    echo "Usage: ./hcf.sh num1 num2"
    exit 1
elif [ $2 -eq 0 ]; then
    echo "Exception: division by 0"
    exit 2
else
    a=$1
    b=$2
    rem=$b
    while [ $rem -ne 0 ]; do
        rem=$((a % b))
        a=$b
        b=$rem
    done
fi
 echo "$a"
