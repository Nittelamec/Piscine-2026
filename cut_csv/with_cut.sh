#!/bin/sh

if [ $# -ne 2 ]; then
    exit 1
fi
if [ ! -f "$1" ]; then
    exit 1
fi
if [ -z "${2##*[!0-9]*}" ]; then
    exit 1
fi
if [ "$2" -lt 0 ]; then
    exit 1
fi
if [ $(wc -l < "$1") -lt "$2" ]; then
    exit 1
fi

head -n "$2" "$1" | tail -n 1 | cut -d ';' -f 2,3 --output-delimiter=' is '
exit 0
