CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: dz1

dz1: dz1.o main.o
	$(CC) $(CFLAGS) -o dz1 dz1.o main.o

dz1.o: dz1.c dz1.h
	$(CC) $(CFLAGS) -c dz1.c

main.o: main.c dz1.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o dz1