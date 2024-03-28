CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

OBJS = fifo_access.o fifo_setup_destroy.o

library: ${OBJS}
	ar csr  libfifo.a ${OBJS}

clean:
	${RM} ${OBJS} libfifo.a

