#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

sed -nE 's/^(([a-z]+ )?[a-z]+ +[*_a-zA-Z0-9]+\(.*\))/\1;/p' < "$1"
