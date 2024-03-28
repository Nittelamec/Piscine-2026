CC = gcc
CFLAGS = -std=c99 -Wvla -Wall -Werror -Wextra -pedantic

OBJS = is_set.o test.o
BIN = is_set

all: ${BIN}

${BIN}: ${OBJS}

clean: 
	${RM} ${OBJS} ${BIN}

.PHONY: clean all
