CC=g++
CFLAGS=-Wall -I. -std=c++11

NQueens.o: nqueens.cpp
	$(CC) $(CFLAGS) -o $@ $^
