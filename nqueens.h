#pragma once
#include <vector>
#include <string>
using namespace std;

enum status{success, invalid_args};

class nQueens {
private:
	int N;
	vector<bool> bboard;
	bool output;
	bool is_safe(vector<bool> board, int x, int y);
	bool solve_helper(vector<bool> &board, int x);
public:
	nQueens(int n, bool output_);
	bool solve();
	void print_board();
};

string gen_spaces(int n);
int usage_message(char* arg);
