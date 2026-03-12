CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
OBJ = src/host.c src/linkedlist.c src/simulation.c main.c

all:
	$(CC) $(CFLAGS) $(OBJ) -o epidemic

clean:
	rm -f epidemic
