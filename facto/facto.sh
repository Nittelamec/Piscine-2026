#!/bin/sh

var=1
lim=$(($1+1))
if [ $# -ne 1 ]; then
    exit 1
elif [ $1 -eq 0 ]; then
    echo "1"
else
    i=1
    while [ $i -ne $lim ]; do
        var=$((var*=i))
        i=$((i+1))
    done
    echo $var
fi
