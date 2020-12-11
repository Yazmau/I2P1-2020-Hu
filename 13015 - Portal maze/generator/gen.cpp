// I think this code is too ugly to read :( ...
#include "../testlib.h"
#include <queue>
#include <numeric>
using namespace std;
const int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
struct cell {
	int x,y;
	bool operator < (const cell &a) const{
		return x != a.x ? x < a.x : y < a.y;
	}
};
struct block {
	vector<cell> cells;
};
tuple<vector<string>, vector<block>, vector<cell> > genBasicBoard(int n,int m,int row,int col) {
	/* gen a n x m empty board */
	vector<string> board;
	string base = "";
	for(int i=0;i<m;i++)	base += ".";
	for(int i=0;i<n;i++)	board.push_back(base);

	/* divide the board into many blocks */
	inf.ensuref(1 <= row && row <= (n + 1) / 3, "row is invalid");
	inf.ensuref(1 <= col && col <= (m + 1) / 3, "col is invalid");
	auto divBoard = [=](int n,int num) -> vector<int> {
		vector<int> idxs;
		for(int i=2,j=1;j < (n + 1)/3;i+=3,j++)
			idxs.push_back(i);
		shuffle(idxs.begin(),idxs.end());
		idxs.erase(idxs.begin() + num - 1,idxs.end());
	
		return idxs;
	};
	vector<int> R = divBoard(n,row), C = divBoard(m,col);
	for(int r : R)	for(int j=0;j<m;j++)	board[r][j] = '#';
	for(int c : C)	for(int i=0;i<n;i++)	board[i][c] = '#';

	/* get every block */
	vector<block> blocks;
	vector<cell> wallCells;
	set<cell> vis;
	auto bfs = [&](cell st) -> block {
		block ret;
		
		queue<cell> q;
		q.push(st);
		vis.insert(st);
		while(!q.empty()) {
			cell now = q.front();	q.pop();
			int x = now.x, y = now.y;
			if((x&1) && (y&1))
				wallCells.push_back(now);
			else
				ret.cells.push_back(now);
			for(int dir=0;dir<4;dir++) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if(board[nx][ny] == '#' || vis.count(cell{nx,ny}) == 1)	continue;
				q.push(cell{nx,ny});
				vis.insert(cell{nx,ny});
			}
		}
	
		 sort(ret.cells.begin(),ret.cells.end());
		// shuffle(ret.cells.begin(),ret.cells.end());
		return ret;
	};
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(board[i][j] != '#' && vis.count(cell{i,j}) == 0)
				blocks.push_back(bfs(cell{i,j}));

	return {board, blocks, wallCells};
}
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);
	int testNumber = atoi(argv[2]);
	
	int T = (subtask == 1 && testNumber == 1 ? 1 : 10);
	vector<int> N,M;
	vector<vector<string> > S;

	for(int t=1;t<=T;t++) {
		int n = (subtask != 3 ? 10 : rnd.next(250,300)), m = (subtask != 3 ? 10 : rnd.next(250,300));
	
		/* decide answer */
		bool ans = (bool)rnd.next(0,1);

		/* decide how to divide the board */
		int row,col;
		{
			if(subtask == 1 && ans)
				row = col = 1;
			else if(subtask != 3)
				row = col = 2;
			else {
				int maxRow = (n + 1) / 3, maxCol = (m + 1) / 3;
				// row = rnd.next(1,maxRow);
				row = maxRow / (t + 1);
				// col = rnd.next(1,maxCol);
				col = maxCol / 2 / (t + 1);
			}
		}

		/* gen the board */
		auto [board, blocks, wallCells] = genBasicBoard(n,m,row,col);
		int blockNum = (int)blocks.size();

		/* decide start and end */
		int stBlock = rnd.next(0,blockNum - 1);
		int edBlock = rnd.next(0,blockNum - 1);
		if(ans && (subtask != 1 && ((testNumber != 10 && testNumber % 3 == 2) || (testNumber == 10 && t % 3 == 2))))
			edBlock = stBlock;
		
		/* set start and end */
		auto randomCell = [&](int blockIdx) -> cell {
			inf.ensuref(!blocks[blockIdx].cells.empty(), "block must not be empty");
			int pos = rnd.next(0,(int)blocks[blockIdx].cells.size() - 1);
			cell ret = blocks[blockIdx].cells[pos];
			blocks[blockIdx].cells.erase(blocks[blockIdx].cells.begin() + pos);
			return ret;
		};
		if(subtask == 1 && testNumber <= 2) {
			board[0][0] = '$';
			board[n - 1][m - 1] = '&';
			blocks[0].cells.erase(blocks[0].cells.begin());
			for(int i=0;i<blockNum;i++)
				if(blocks[i].cells.back().x == n - 1 && blocks[i].cells.back().y == m - 1) {
					blocks[i].cells.pop_back();
					break;
				}
			for(int i=0;i<(int)wallCells.size();i++)
				if(wallCells[i].x == n - 1 && wallCells[i].y == m - 1) {
					wallCells.erase(wallCells.begin() + i);
					break;
				}
		}
		else {
			cell st = randomCell(stBlock);
			board[st.x][st.y] = '$';
			
			cell ed = randomCell(edBlock);
			board[ed.x][ed.y] = '&';
		}
		
		//  set gates
		auto buildGate = [&](int u,int v,int alpha,bool ignoreV=false) -> void {
			inf.ensuref(0 <= u && u < blockNum,"invalid gate building");	
			inf.ensuref(0 <= v && v < blockNum,"invalid gate building");	
			
			cell from = randomCell(u);
			board[from.x][from.y] = 'a' + alpha;
			if(!ignoreV) {
				cell to = randomCell(v);
				board[to.x][to.y] = 'A' + alpha;
			}
		};
		if(subtask != 1) {
			vector<int> alphas(26);
			iota(alphas.begin(),alphas.end(),0);
			shuffle(alphas.begin(),alphas.end());
			if(testNumber % 3 == 2 || (testNumber == 10 && t % 3 == 2)) {	// you must not enter in any gate
				int gateNum = (subtask == 2 ? rnd.next(1,3) : rnd.next(3,26));

				int u = stBlock, v;
				do {
					v = rnd.next(0,blockNum - 1);
				} while(u == v || blocks[v].cells.empty());
				buildGate(u,v,alphas[0]);
				for(int i=1;i<gateNum;i++) {
					while(true) {
						u = rnd.next(0,blockNum - 1);
						v = rnd.next(0,blockNum - 1);
						if(blocks[u].cells.empty() || blocks[v].cells.empty() || v == stBlock)	continue;
						buildGate(u,v,alphas[i]);
						break;
					}
				}
			}
			else {	// random
				int cur = 0;
				if(ans) {
					int midwayGateNum = (subtask == 2 ? 1 : rnd.next(1,10));
					inf.ensuref(!blocks[stBlock].cells.empty() && !blocks[edBlock].cells.empty(),"st ed fail");
					int u = stBlock;
					for(int i=0;i<midwayGateNum;i++) {
						while(true) {
							int v = rnd.next(0,blockNum - 1);
							if(v == edBlock || (int)blocks[v].cells.size() < 2)	continue;
							buildGate(u,v,alphas[cur++]);
							u = v;
							break;
						}
					}
					buildGate(u,edBlock,alphas[cur++]);
				}

				bool edSurrounded = (testNumber % 3 == 0 || (testNumber == 10 && t % 3 == 0));
			
				if(subtask != 2) {
					int gateNum = rnd.next(15,26 - (edSurrounded ? 4 : 0));
					for(int i=cur;i<gateNum;i++) {
						while(true) {
							int u = rnd.next(0,blockNum - 1);
							int v = rnd.next(0,blockNum - 1);
							if(blocks[u].cells.empty() || blocks[v].cells.empty())	continue;
							buildGate(u,v,alphas[cur++]);
							break;
						}
					}
				}
				if(edSurrounded) {
					int edX, edY;
					for(int i=0;i<n;i++)	for(int j=0;j<m;j++)	if(board[i][j] == '&')	edX = i, edY = j;
					for(int dir=0;dir<4;dir++) {
						int nx = edX + dx[dir], ny = edY + dy[dir];
						if(nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;
						if(board[nx][ny] != '.')	continue;
						while(true) {
							int u = rnd.next(0,blockNum - 1);
							if(u == edBlock || blocks[u].cells.empty())	continue;
							buildGate(u,edBlock,alphas[cur],true);
							board[nx][ny] = (char)('A' + alphas[cur++]);
							for(int i=0;i<blockNum;i++)
								for(int j=0;j<(int)blocks[i].cells.size();j++)
									if(blocks[i].cells[j].x == nx && blocks[i].cells[j].y == ny) {
										blocks[i].cells.erase(blocks[i].cells.begin() + j);
										break;
									}
							for(int i=0;i<(int)wallCells.size();i++)
								if(wallCells[i].x == nx && wallCells[i].y == ny) {
									wallCells.erase(wallCells.begin() + i);
									break;
								}
							break;
						}
					}
				}
			}
		}

		//  set some trash wall
		int trashWallNum = rnd.next(1,(int)wallCells.size());
		shuffle(wallCells.begin(),wallCells.end());
		for(int i=0;i<trashWallNum;i++)
			board[wallCells[i].x][wallCells[i].y] = '#';

		// special gen for testcase 10
		if(testNumber == 10 && t >= 7) {
			string temp = "$&";
			if(t != 10) {	// not empty board
				for(int i=0;i<26;i++)
					temp = temp + (char)('a' + i) + (char)('A' + i);
			}
			int wallNum = rnd.next(1,(n * m - (int)temp.size()) / 10);
			for(int i=0;i<wallNum;i++)	temp += '#';
			for(int i=(int)temp.size();i<n * m;i++)	temp += '.';
			shuffle(temp.begin(),temp.end());
			
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					board[i][j] = temp[i * m + j];
		}

		N.push_back(n);	M.push_back(m);	S.push_back(board);
	}
	cout << T << '\n';
	for(int t=0;t<T;t++) {
		cout << N[t] << " " << M[t] << '\n';
		for(int i=0;i<N[t];i++)
			cout << S[t][i] << '\n';
	}
	return 0;
}
