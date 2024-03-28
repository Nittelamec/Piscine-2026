##
# Project Title
#
# @file
# @version 0.1
CC=gcc
CFLAGS=-g3 -Wall -Wextra -Werror -Wvla -std=c99

my_strcpy: object
	$(CC) $(CFLAGS) main.o my_strcpy.o -o my_strcpy

object:
	$(CC) $(CFLAGS) -c main.c my_strcpy.c
# end
