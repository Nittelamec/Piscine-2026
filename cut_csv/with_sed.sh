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

sed -n "$2p" < "$1"  | sed -nE "s/([^;]+);([^;]+);([^;]+);([^;]+);.*/\2 is \3/p"
exit 0
