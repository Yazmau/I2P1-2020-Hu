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
	
	int T = (subtask == 1 ? 1 : 10);
	vector<int> K;
	vector<string> A,B;

	int _maxK[] = {3,1,2,0,4,5,6,7,8,9};
	int maxK = _maxK[testNumber - 1];

	for(int t=1;t<=T;t++) {
		int k = ((t&1) ? maxK : rnd.next(0,maxK));
	
		string a,b;

		while(true) {
			a = tran(rnd.next(0,8),rnd.next(0,(1<<8) - 1));

			if(t&1) {
				int step = (rnd.next(0,1) == 0 ? k + 1 : rnd.next(0,k));
				
				set<Puzzle> vis;
				queue<Puzzle> q;

				Puzzle init(a,0);
				q.push(init);
				vis.insert(init);
				
				vector<string> bPool;
				while(!q.empty()) {
					Puzzle now = q.front();
					q.pop();
					
					if(now.dis == step)
						bPool.push_back(now.get());
					else {
						for(int i=0;i<4;i++)
							if(now.checkOpValid(i)) {
								Puzzle nxt = now.op(i);
								if(vis.count(nxt) == 0) {
									q.push(nxt);
									vis.insert(nxt);
								}
							}
					}
				}

				if(bPool.empty())	continue;
				b = bPool[rnd.next(0, (int)bPool.size() - 1)];
			}
			else
				b = tran(rnd.next(0,8),rnd.next(0,(1<<8) - 1));
			break;
		}
		
		K.push_back(k);
		A.push_back(a);
		B.push_back(b);
	}

	cout << T << '\n';
	for(int t=0;t<T;t++) {
		cout << K[t] << '\n';
		for(string s : {A[t],B[t]})
			for(int i=0;i<9;i++) {
				cout << s[i];
				if((i + 1) % 3 == 0)	cout << '\n';
			}
	}
	return 0;
}
