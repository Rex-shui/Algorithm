SOURCES=$(wildcard *.c)
CC = gcc

all:
	$(CC) $(SOURCES) -o test
