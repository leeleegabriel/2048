CC = gcc
CFLAGS = -Wall
DEPS = ./lib/helpers.h
OBJ = 2048.o ./lib/helpers.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

default: $(OBJ)
	gcc $(CFLAGS) -o 2048 $^