SOURCE = main.c tools.c queue.c stack.c binarySearchTree.c
CC = gcc

all:
	$(CC) $(SOURCE) -o test
