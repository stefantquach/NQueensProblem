#include <iostream>
#include "header.h"
using namespace std;

int main(int argc, char* argv[]) {
	nQueens p = nQueens(stoi(argv[1],nullptr,0), false);
	p.solve();
	p.print_board();
	return success;
}

nQueens::nQueens(int n, bool output_)
:N(n), output(output_){
	for(int i=0; i<n*n; ++i) {
		bboard.push_back(false);
	}
}

bool nQueens::is_safe(vector<bool> board, int x, int y) {
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
			board[N*y+x] = true;
			if(solve_helper(board, x+1)) {
				return true;
			}
			// if false go back up the tree
			board[N*y+x] = false;
		}
	}
	return false;
 }

 bool nQueens::solve() {
	 return solve_helper(bboard, 0);
 }

 void nQueens::print_board() {
	 cout << "  ";
	 for (int i=0; i<N; ++i) {
		 cout << i << " ";
	 }
	 cout << endl;
	 for(int y=0; y<N; ++y) {
		 cout << y << " ";
		 for(int x=0; x<N; ++x) {
			 cout << (bboard[N*y+x] ? "q":".")  << " ";
		 }
		 cout << endl;
	 }
	 cout << endl;
 }
