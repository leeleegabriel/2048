CC = gcc
CFLAGS = -Wall

default:
	gcc $(CFLAGS) -o 2048 2048.c ./lib/helpers.c
	gcc $(CFLAGS) -o ai 2048_ai.c ./lib/helpers.c ./lib/ai.c -O3

clean:
	rm -rf *.o ./lib/*.o ai ai_* 2048