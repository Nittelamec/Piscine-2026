#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi
if [ -f "$1" ]; then
    while IFS= read -r line; do
        cpt=$(printf "%s" "$line" | wc -c)
        if [ "$cpt" -ge 80 ]; then
            printf "%s\n" "$line"
        fi
    done < "$1"
    exit 0
fi
exit 1
