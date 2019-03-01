#pragma once
#include <vector>
using namespace std;

enum status{success, invalid_args};

class nQueens {
private:
	int N;
	vector<bool> bboard;
	bool output;
public:
	nQueens(int n, bool output_);
	bool is_safe(vector<bool> board, int x, int y);
	bool solve_helper(vector<bool> &board, int x);
	bool solve();
	void print_board();
};
