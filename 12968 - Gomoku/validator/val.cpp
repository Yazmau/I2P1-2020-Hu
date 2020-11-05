/*
1 <= q <= 100
*/
#include "boardlib.hpp"
extern int SZ;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	// input q
	int q = inf.readInt(1, 100, "q");
	inf.readEoln();
	
	for(int t=0;t<q;t++) {
		// input board
		vector<string> board;
		for(int i=0;i<SZ;i++) {
			string row = inf.readWord();
			board.push_back(row);
			inf.readEoln();
		}

		// check content and length
		for(int i=0;i<SZ;i++) {
			inf.ensuref((int)board[i].size() == SZ, "the length of some board's row is wrong");
			for(char c : board[i])
				inf.ensuref(c == '.' || c == 'b' || c == 'w', "thers is a cell which is not '.' nor 'b' nor 'w'");
		}

		inf.ensuref(Board::checkNumberValid(board), "the number stones is invalid");
		inf.ensuref(Board::checkNoTwoWinner(board), "both black and white are winner");		
		inf.ensuref(Board::checkNoInvalidWin(board), "winning placement is invalid");
	}

	inf.readEof();
	return 0;
}
