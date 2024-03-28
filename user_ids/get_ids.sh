#!/bin/sh

cut -d ':' -f 3 '/etc/passwd' | sort -h -r -u
exit 0
