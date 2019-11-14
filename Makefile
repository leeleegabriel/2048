CC = gcc
CFLAGS = -Wall
DEPS = ./lib/helpers.h

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

default: 2048.o $(OBJ)
	gcc $(CFLAGS) -o 2048 2048.c ./lib/helpers.c

ai:
	gcc $(CFLAGS) -o ai 2048_ai.c ./lib/helpers.c


clean:
	rm -rf *.o ./lib/*.o ai 2048