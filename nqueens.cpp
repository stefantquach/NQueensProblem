#include <iostream>
#include "nqueens.h"
using namespace std;

nQueens::nQueens(int n, bool output_)
:N(n), output(output_){
	for(int i=0; i<n*n; ++i) {
		bboard.push_back(false);
	}
}

bool nQueens::is_safe(vector<bool> board, int x, int y) {
	// for all these cases, we only need to check for queens to the left
	// checking horizontally
	for(int x_=x-1; x_>=0; --x_) {
		if(board[N*y + x_]) {
			if(output)
				cout << "Queen at " << x << "," << y << " would be killed by " << x_ << "," << y << endl;
			return false;
		}
	}

	// checking main diag
	for(int i=0; x-i>=0 && y-i >= 0; ++i) {
		if(board[N*(y-i) + (x-i)]) {
			if(output)
				cout << "Queen at " << x << "," << y << " would be killed by " << x-i << "," << y-i << endl;
			return false;
		}
	}

	// checking sub diag
	for(int i=0; x-i>=0 && y+i < N; ++i) {
		if(board[N*(y+i) + (x-i)]) {
			if(output)
				cout << "Queen at " << x << "," << y << " would be killed by " << x-i << "," << y+i << endl;
			return false;
		}
	}

	// else is safe
	return true;
}

bool nQueens::solve_helper(vector<bool> &board, int x) {
	if(x >= N) {
		return true;
	}
	for(int y=0; y<N; ++y) {
		if(is_safe(board, x, y)){
			board[N*y+x] = true; // place queen at spot
			if(solve_helper(board, x+1)) { // check the next column
				return true; // if the next column is true then this spot is safe
			}
			// if false go back up the tree
			board[N*y+x] = false; // removing the queen we placed
		}
	}
	return false;
 }

bool nQueens::solve() {
	 return solve_helper(bboard, 0);
 }

void nQueens::print_board() {
	 cout << gen_spaces(N/10+2);
	 for (int i=0; i<N; ++i) {
		 cout << i << gen_spaces(1+N/10-i/10);
	 }
	 cout << endl;
	 for(int y=0; y<N; ++y) {
		 cout << y << gen_spaces(1+N/10-y/10);
		 for(int x=0; x<N; ++x) {
			 cout << (bboard[N*y+x] ? "q":".")  << gen_spaces(N/10+1);
		 }
		 cout << endl;
	 }
	 cout << endl;
 }

string gen_spaces(int n) {
	 string o;
	 for(int i=0; i<n; ++i) {
		 o += " ";
	 }
	 return o;
 }

int usage_message(char* arg) {
	 cerr << "Invalid arguments" << endl;
	 cout << "Usage: " << arg << " <n> [-d debug]" << endl;
	 return invalid_args;
 }
