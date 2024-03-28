CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic

OBJS= treshold1.o treshold2.o treshold3.o treshold4.o treshold5.o treshold6.o

library: ${OBJS}
	ar csr libdlist.a ${OBJS}
clean:
	${RM} ${OBJS} libdlist.a



