CC=g++
CFLAGS=-Wall -I. -std=c++11

NQueens.out: nqueens.cpp
	$(CC) $(CFLAGS) -o $@ $^
