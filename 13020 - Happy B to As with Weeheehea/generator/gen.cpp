#include "../testlib.h"
#include<queue>
using namespace std;
string tran(int xPos,int val) {
	string ret = "";
	for(int i=0;i<9;i++)
		if(i == xPos)
			ret += "x";
		else {
			ret += (char)('0' + (val & 1));
			val >>= 1;
		}
	return ret;
}
string genBoard(int _1Num) {
	int xPos = rnd.next(0,8);
	string temp = "";
	for(int i=0;i<_1Num;i++)	temp += '1';
	while((int)temp.size() < 8)	temp += '0';
	shuffle(temp.begin(),temp.end());
	int val = stoi(temp,nullptr,2);
	return tran(xPos,val);
}
const int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
class Puzzle {
	private:
		string s;
		int x,y;
	public:
		int dis;
		Puzzle() {}
		Puzzle(string _s,int _dis) {
			s = _s;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(s[i * 3 + j] == 'x')
						x = i, y = j;
			dis = _dis;
		}
		bool operator < (const Puzzle &a) const{
			return s < a.s;
		}
		bool checkOpValid(int dir) {
			if(dir < 0 || dir >= 4)	return false;
			int nx = x + dx[dir], ny = y + dy[dir];
			return (0 <= nx && nx < 3 && 0 <= ny && ny < 3);
		}
		Puzzle op(int dir) {
			int nx = x + dx[dir], ny = y + dy[dir];
			swap(s[nx * 3 + ny],s[x * 3 + y]);
			string temp = s;
			swap(s[nx * 3 + ny],s[x * 3 + y]);
			return Puzzle(temp, dis + 1);
		}
		string get() {
			return s;
		}
};
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);
	int testNumber = atoi(argv[2]);

	int _N[] = {4,5,7,8,8,10,100000,100000};
	int N = _N[testNumber - 1];

	int _K[] = {2,3,4,5,5,7,7,10};
	int K = _K[testNumber - 1];

	vector<string> A;
	string B;

	if(testNumber == 1) {
		A = {"0x0101001","0001x1001","000011x01","00110x001"};
		B = "0x0101001";
	}
	else {
		int _1Num = (testNumber <= 6 ? rnd.next(1,7) : 4);
		B = genBoard(_1Num);
		
		set<Puzzle> vis;
		queue<Puzzle> q;
		
		Puzzle init(B,0);
		q.push(init);
		vis.insert(init);

		vector<string> validPuzzlePool,invalidPuzzlePool;
		while(!q.empty()) {
			Puzzle now = q.front();
			q.pop();

			if(now.dis <= K)
				validPuzzlePool.push_back(now.get());
			else
				invalidPuzzlePool.push_back(now.get());

			if(now.dis > K)	continue;
			for(int i=0;i<4;i++)
				if(now.checkOpValid(i)) {
					Puzzle nxt = now.op(i);
					if(vis.count(nxt) == 0) {
						q.push(nxt);
						vis.insert(nxt);
					}
				}
		}

		bool duplicatePuzzleEnable = (testNumber > 4);
		bool randomPuzzleEnable = (testNumber == 4 || testNumber > 5);
		
		shuffle(validPuzzlePool.begin(),validPuzzlePool.end());
		shuffle(invalidPuzzlePool.begin(),invalidPuzzlePool.end());
		
		vis.clear();
		auto update = [&](string newPuzzle)->void {
			inf.ensuref(duplicatePuzzleEnable || vis.count(Puzzle(newPuzzle,-1)) == 0, "fail: duplicate puzzle");
			vis.insert(Puzzle(newPuzzle,-1));
			A.push_back(newPuzzle);
		};

		int succesNum = rnd.next(2,N - 2);
		if(duplicatePuzzleEnable)
			update(validPuzzlePool[0]);
		for(int i=0;i < (int)validPuzzlePool.size() && (int)A.size() < succesNum;i++)
			update(validPuzzlePool[i]);
		while((int)A.size() < succesNum)
			update(validPuzzlePool[rnd.next(0,(int)validPuzzlePool.size() - 1)]);
		
		if(duplicatePuzzleEnable)
			update(invalidPuzzlePool[0]);
		for(int i=0;i < (int)invalidPuzzlePool.size() && (int)A.size() < N;i++) {
			int type = rnd.next(0,2);
			if(i == 0 || !randomPuzzleEnable)	type = 2;
			
			string newPuzzle;
			if(type == 0)
				newPuzzle = tran(rnd.next(0,8),rnd.next(0,(1 << 8) - 1));
			else if(type == 1)
				newPuzzle = genBoard(_1Num);
			else
				newPuzzle = invalidPuzzlePool[i];
			update(newPuzzle);
		}
		while((int)A.size() < N) {
			int type = rnd.next(0,2);
			if(!randomPuzzleEnable)	type = 2;

			string newPuzzle;
			if(type == 0)
				newPuzzle = tran(rnd.next(0,8),rnd.next(0,(1 << 8) - 1));
			else if(type == 1)
				newPuzzle = genBoard(_1Num);
			else
				newPuzzle = invalidPuzzlePool[rnd.next(0,(int)invalidPuzzlePool.size() - 1)];
			update(newPuzzle);
		}

		shuffle(A.begin(),A.end());
	}

	cout << N << " " << K << '\n';
	for(string s : A)
		for(int i=0;i<9;i++) {
			cout << s[i];
			if((i + 1) % 3 == 0)	cout << '\n';
		}
	for(int i=0;i<9;i++) {
		cout << B[i];
		if((i + 1) % 3 == 0)	cout << '\n';
	}
	return 0;
}
