#!/bin/sh

FIRST="$1"
LAST="$3"
INCR="$2"

if [ $# -ne 3 ]; then
    echo 'Usage: ./seq.sh FIRST INCREMENT LAST' >&2
    exit 1
fi
if [ $INCR -eq 0 ]; then
    exit 1
fi
if [ $FIRST -eq $LAST ]; then
    echo $FIRST
    exit 0
fi


if [ $FIRST -lt $LAST ]; then
    if [ $INCR -lt 0 ]; then
        exit 1
    fi
fi
if [ $FIRST -gt $LAST ]; then
    if [ $INCR -gt 0 ]; then
        exit 1
    fi
fi
while [ $FIRST -ne $LAST ]; do
    echo $FIRST
    FIRST=$((FIRST + INCR))
    if [ $INCR -lt 0 ]; then
        if [ $FIRST -lt $LAST ]; then
            exit 0
        fi
    else
        if [ $FIRST -gt $LAST ]; then
            exit 0
        fi
    fi
done
echo $FIRST
exit 0
