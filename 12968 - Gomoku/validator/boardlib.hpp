#include "../testlib.h"
using namespace std;
int SZ = 15;
class Board {
	public:
		static bool checkNumberValid(vector<string> &board) {
			// suppose black always moves first
			int cntB = 0, cntW = 0;
			for(int i=0;i<SZ;i++)
				for(char c : board[i])
					if(c == 'b')
						cntB++;
					else if(c == 'w')
						cntW++;
			return 0 <= cntB - cntW && cntB - cntW <= 1;
		}
		static int jumpX(int x,int direction,int step) {
			inf.ensuref(0 <= direction && direction < 4, "jump direction is invalid");
			static int deltaX[] = {1,0,1,1};
			return x + deltaX[direction] * step;
		}
		static int jumpY(int y,int direction,int step) {
			inf.ensuref(0 <= direction && direction < 4, "jump direction is invalid");
			static int deltaY[] = {0,1,1,-1};
			return y + deltaY[direction] * step;
		}
		/*
			check whether the chain begin at (x,y) in given direction is an unbroken chain by specific player

			return -1: the chain is out of the bounds
			return  0: it's not an unbroken chain
			return  1: it's an unbroken chain
		*/
		static int checkUnbrokenChain(vector<string> &board,int x,int y,char player,int direction) {
			int cnt = 0;
			for(int step=0;step<5;step++) {
				int nowX = jumpX(x,direction,step), nowY = jumpY(y,direction,step);
				if(nowX < 0 || nowX >= SZ || nowY < 0 || nowY >= SZ)	return -1;
				if(board[nowX][nowY] == player)	cnt++;
			}
			return (cnt == 5 ? 1 : 0);
		}
		static bool checkSpecificPlayerWin(vector<string> &board,char player) {
			for(int i=0;i<SZ;i++)
				for(int j=0;j<SZ;j++)
					for(int direction=0;direction<4;direction++)
						if(checkUnbrokenChain(board,i,j,player,direction) == 1)
							return true;
			return false;
		}
		static bool checkNoTwoWinner(vector<string> &board) {
			int cnt = 0;
			for(char player : {'b','w'})
				if(checkSpecificPlayerWin(board, player))
					cnt++;
			return cnt < 2;
		}
		/*
			check whether the winning placement is valid (i.e. exist a stone such that erasing it will cause no wineer)
		*/
		static bool checkNoInvalidWin(vector<string> &board) {
			for(int i=0;i<SZ;i++)
				for(int j=0;j<SZ;j++) {
					char oriStone = board[i][j];
					board[i][j] = '.';
					if(checkNumberValid(board)) {
						bool winner = false;
						for(char player : {'b','w'})
							winner |= checkSpecificPlayerWin(board,  player);
						board[i][j] = oriStone;
						if(!winner)	return true;
					}
					else
						board[i][j] = oriStone;
				}
			return false;
		}
};
