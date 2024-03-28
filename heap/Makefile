CC = gcc
CFLAGS =-std=c99 -Wall -Wextra -Werror -Wvla -pedantic

OBJS = add.o create.o del.o pop.o print.o

library: ${OBJS}
	ar csr libheap.a ${OBJS}
clean:
	${RM} ${OBJS} libheap.a



