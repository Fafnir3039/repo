CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: program

program: main.o dz1.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c dz1.h
	$(CC) $(CFLAGS) -c main.c

dz1.o: dz1.c dz1.h
	$(CC) $(CFLAGS) -c dz1.c

clean:
	rm -f *.o program

.PHONY: all clean
