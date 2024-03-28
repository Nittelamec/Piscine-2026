CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

OBJS = vector.o

library: ${OBJS}
	ar csr libvector.a ${OBJS}

clean:
	${RM} ${OBJS} libvector.a
