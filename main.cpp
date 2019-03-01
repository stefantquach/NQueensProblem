#include <iostream>
#include "nqueens.h"
using namespace std;

int main(int argc, char* argv[]) {
	if(argc == 2) {
		int n;
		try {
			n = stoi(argv[1]);
		} catch(invalid_argument){
			return usage_message(argv[0]);
		}
		nQueens p = nQueens(n, false);
		p.solve();
		p.print_board();
		return success;
	} else if (argc == 3 && string(argv[2]) == "-d") {
		int n;
		try {
			n = stoi(argv[1]);
		} catch(invalid_argument){
			return usage_message(argv[0]);
		}
		nQueens p = nQueens(n, true);
		p.solve();
		p.print_board();
		return success;
	} else {
		return usage_message(argv[0]);
	}
}
