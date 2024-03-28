#!/bin/sh
if [ $# -gt 1 ]; then
    exit 1
fi

if [ $# -eq 1 ]; then
    echo "$(($1))"
else
    while read -r var; do
        echo "$(($var))"
    done
fi
