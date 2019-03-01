CC=g++
CFLAGS=-Wall -I. -std=c++11

NQueens.out: main.cpp nqueens.cpp
	$(CC) $(CFLAGS) -o $@ $^
