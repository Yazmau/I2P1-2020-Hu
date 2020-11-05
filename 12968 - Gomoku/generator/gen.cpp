#include "../validator/boardlib.hpp"
extern int SZ;
/* keep adding stones on the board without making any unbroken chain */
void genBoard(vector<string> &board,bool boundEnable,char winner) {
	auto calStoneDiff = [=]()->int {
		int ret = (winner == 'b' ? 1 : (winner == 'w' ? -1 : 0));
		for(int i=0;i<SZ;i++)
			for(int j=0;j<SZ;j++)
				if(board[i][j] == 'b')
					ret++;
				else if(board[i][j] == 'w')
					ret--;
		return ret;
	};
	int stoneDiff = calStoneDiff();
	
	struct cell {
		int x,y;
	};
	vector<cell> cells;
	struct op {
		int idx;
		char player;
	};
	/* try to add some stones */
	auto updateCells = [&](vector<op> ops)->bool {
		vector<char> oriStones;
		for(op now : ops) {
			int x = cells[now.idx].x, y = cells[now.idx].y;
			oriStones.push_back(board[x][y]);
			board[x][y] = now.player;
		}
		if(Board::checkSpecificPlayerWin(board, 'b') || Board::checkSpecificPlayerWin(board, 'w')) {
			for(int i=0;i<(int)ops.size();i++) {
				int x = cells[ops[i].idx].x, y = cells[ops[i].idx].y;
				char oriStone = oriStones[i];
				board[x][y] = oriStone;
			}
			return false;
		}
		else {
			for(int i=(int)ops.size()-1;i>=0;i--)
				cells.erase(cells.begin() + ops[i].idx);
			return true;
		}
	};

	for(int i=0;i<SZ;i++)
		for(int j=0;j<SZ;j++)
			if(boundEnable || i != 0 || j != 0)
				if(board[i][j] == '.')
					cells.push_back(cell{i,j});
	int expectStoneDiff = (winner == 'w' ? 0 : (winner == 'b' ? 1 : rnd.next(0,1)));
	for(int i=(int)cells.size()-1;i>=0 && stoneDiff < expectStoneDiff;i--)
		if(updateCells(vector<op>{op{i,'b'}}))
			stoneDiff++;
	for(int i=(int)cells.size()-1;i>=0 && stoneDiff > expectStoneDiff;i--)
		if(updateCells(vector<op>{op{i,'w'}}))
			stoneDiff--;
	inf.ensuref(stoneDiff == expectStoneDiff, "stoneDiff doesn't become what it is expected");

	static const int iterLimit = 30;
	int cellsLimit = (boundEnable ? rnd.next(2,SZ * SZ - 50) : SZ * SZ - 20);
	while((int)cells.size() >= cellsLimit) {
		int iter = 0;
		for(;iter<iterLimit;iter++) {
			int a = rnd.next(0,(int)cells.size() - 1);
			int b = rnd.next(0,(int)cells.size() - 1);
			if(a == b)	continue;
			if(a > b)	swap(a,b);
			if(updateCells(vector<op>{op{a,'b'},op{b,'w'}}))	break;
		}
		if(iter == iterLimit)	break;
	}
}
void avoidMultipleChain(vector<string> &board,int tx,int ty,char loser,int avoidDirectionState,bool chainLen5) {
	/* slack implementation */
	for(int direction=0;direction<4;direction++,avoidDirectionState>>=1) {
		vector<int> steps;
		if(avoidDirectionState & 1)
			steps = {-1,1};
		else if(chainLen5)
			steps = {-1,5};
			
		for(int step : steps) {
			int x = Board::jumpX(tx,direction,step), y = Board::jumpY(ty,direction,step);
			if(x < 0 || x >= SZ || y < 0 || y >= SZ)	continue;
			board[x][y] = loser;
		}
	}
}
vector<string> genBoardWithChain(int chainDirectionState,bool boundEnable,bool chainLen5=false) {
	vector<string> ret;
	string emptyRow = "";
	for(int i=0;i<SZ;i++)	emptyRow += '.';
	for(int i=0;i<SZ;i++)	ret.push_back(emptyRow); 
	// the length of the unbroken chain
	int chainLen = 5;
	// the upper-left coordinate
	int minX = 0, maxX = SZ - 1, minY = 0, maxY = SZ - 1;
	for(int chainDirection=0,base=1;chainDirection<4;chainDirection++,base<<=1)
		if(chainDirectionState & base) {
			minX = max(minX, (boundEnable ? 0 : 1));
			maxX = min(maxX, SZ - (boundEnable ? 1 : 2) - Board::jumpX(0,chainDirection,chainLen - 1));
		
			if(chainDirection != 3) {
				minY = max(minY, (boundEnable ? 0 : 1));
				maxY = min(maxY, SZ - (boundEnable ? 1 : 2) - Board::jumpY(0,chainDirection,chainLen - 1));
			}
			else {
				minY = max(minY, chainLen + (boundEnable ? -1 : 0)); 
				maxY = min(maxY, (boundEnable ? SZ - 1 : SZ - 2));
			}
		}
	int x = rnd.next(minX,maxX), y = rnd.next(minY,maxY);
	// the winner
	string players = "bw";
	int winPlayer = rnd.next(0,1);
	
	/* the pre-placement of stones(the unbroken chain and the stones which are used to avoid multiple chain) */
	for(int chainDirection=0,base=1;chainDirection<4;chainDirection++,base<<=1)
		if(chainDirectionState & base)
			for(int step=1;step<chainLen;step++)
				ret[Board::jumpX(x,chainDirection,step)][Board::jumpY(y,chainDirection,step)] = players[winPlayer];
	ret[x][y] = 'x';
	avoidMultipleChain(ret, x, y, players[winPlayer ^ 1], ((1 << 4) - 1) ^ chainDirectionState,chainLen5);
	
	genBoard(ret, boundEnable, players[winPlayer]);
	ret[x][y] = players[winPlayer];

	return ret;
}
vector<string> genBoardByStrategy(int num) {
	inf.ensuref(0 <= num && num <= 9, "strategy number is invalid");

	vector<string> ret;
	string emptyRow = "";
	for(int i=0;i<SZ;i++)	emptyRow += '.';
	switch(num) {
		case 0:
			for(int i=0;i<SZ;i++)	ret.push_back(emptyRow);
			genBoard(ret, false, '@');
			break;
		case 1:
			ret = genBoardWithChain((1<<0),false,true);
			break;
		case 2:
			ret = genBoardWithChain((1<<1),false,true);
			break;
		case 3:
			ret = genBoardWithChain((1<<2),false,true);
			break;
		case 4:
			ret = genBoardWithChain((1<<3),false,true);
			break;
		case 5:
			ret = genBoardWithChain((1<<rnd.next(0,3)),true);
			break;
		case 6:
			{
				for(int i=0;i<SZ;i++)	ret.push_back(emptyRow);
				int r = rnd.next(0,SZ - 2);
				if(rnd.next(0,5) == r)	r = SZ - 2;
				ret[r][SZ - 1] = ret[r][SZ - 2] = ret[r][SZ - 3] = ret[r][SZ - 4] = ret[r + 1][0] = "bw"[rnd.next(0,1)];
				genBoard(ret, true, '@');
			}
			break;
		case 7:
			{
				int chainDirectionState = 1;
				while(chainDirectionState == (1<<0) || chainDirectionState == (1<<1) || chainDirectionState == (1<<2) || chainDirectionState == (1<<3))
					chainDirectionState = rnd.next(1,(1<<4) - 1);
				ret = genBoardWithChain(chainDirectionState,true);
			}
			break;
		case 8:
			for(int i=0;i<SZ;i++)	ret.push_back(emptyRow);
			for(int i=0;i<SZ;i++)
				for(int j=0;j<SZ;j++)
					ret[i][j] = "bw"[(j + ((i + 1) % 3 == 0) + i / 3) & 1];
			break;
		case 9:
			for(int i=0;i<SZ;i++)	ret.push_back(emptyRow);
			break;
	}
	return ret;
}
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int testnum = atoi(argv[1]);

	// int q = 1;
	int q = (testnum <= 6 ? 30 : 100);
	vector<vector<string> > boards;

	vector<int> strategys[10] = {
		{1},
		{2},
		{1,2},
		{0,1,2},
		{0,1,2,3},
		{0,1,2,4},
		{0,1,2,3,4},
		{0,5,5,5,5,6},
		{0,5,5,5,5,7},
		{0,5,5,5,6,6,6,7,7,7}
	};

	for(int i=0;i<q;i++)
		boards.push_back(genBoardByStrategy(strategys[testnum - 1][i % (int)strategys[testnum - 1].size()]));
	if(testnum == 10) {
		boards[0] = boards[91] = genBoardByStrategy(8);
		boards[1] = boards[90] = genBoardByStrategy(9);
	}

	cout << q << '\n';
	for(auto board : boards)
		for(string row : board)
			cout << row << '\n';
	return 0;
}
