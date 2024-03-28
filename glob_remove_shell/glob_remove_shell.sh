#!/bin/sh

EXTENSION="txt"
list=0

if [ $# -eq 0 ]; then
    for i in *.$EXTENSION; do
        list=$((list + 1))
    done
    if [ $list -eq 0 ]; then
        exit 1
    else
        for i in *.$EXTENSION; do
            rm -r "$i"
        done
    fi
else
    EXTENSION=$1
    for i in *.$EXTENSION; do
        list=$((list + 1))
    done
    if [ $list -eq 0 ]; then
        exit 1
    else
        for i in *.$EXTENSION; do
            rm -r "$i"
        done
    fi
fi
