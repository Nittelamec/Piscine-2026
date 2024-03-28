#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi
if [ -d $1 ]; then
    for var in $(ls "$1"); do
        if [ $(file "$1/$var" | grep -c "ASCII text") -eq 1 ]; then
            echo $(file "$1/$var")
        fi
    done
    exit 0
fi
exit 1
