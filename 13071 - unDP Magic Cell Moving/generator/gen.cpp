#include "../testlib.h"
using namespace std;
struct op {
	int type,dir,val;
};
struct nxt {
	int dir[4] = {-1,-1,-1,-1};
};
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);
	int testNumber = atoi(argv[2]);

	int Q;
	vector<op> ops;

	if(testNumber == 1) {
		Q = 15;
		ops = {op{3,-1,4},op{4,-1,-1},op{1,0,8},op{2,0,-1},op{4,-1,-1},op{1,1,7},op{2,1,-1},
					op{4,-1,-1},op{1,2,6},op{2,2,-1},op{4,-1,-1},op{1,3,3},op{2,3,-1},op{4,-1,-1},op{1,1,74}};
	}
	else {
		Q = (testNumber <= 7 ? 1000 : 100000);
		bool dirEnable[4] = {true,true,true,true};
		bool opEnable[4] = {true,true,true,true};
		bool invalidOpEnable[2] = {true,true};

		if(testNumber <= 5) {
			fill(dirEnable,dirEnable + 4,false);
			if(testNumber&1)
				dirEnable[1] = dirEnable[3] = true;
			else
				dirEnable[0] = dirEnable[2] = true;
		}

		if(testNumber == 8)
			opEnable[2] = false;
		else if(testNumber == 9)
			opEnable[2] = opEnable[3] = false, Q--;

		if(testNumber <= 3 || testNumber == 9)
			invalidOpEnable[0] = false;
		if(testNumber <= 6 || testNumber == 9)
			invalidOpEnable[1] = false;

		int now = 0, cnt = 1;
		vector<nxt> nexts(Q + 5);
		
		for(int i=0;i<Q;i++) {
			int type = rnd.next(1,4);
			while(!opEnable[type - 1])	type = rnd.next(1,4);
			
			int dir = -1;
			if(type == 1 || type == 2) {
				dir = rnd.next(0,3);
				for(int j=0;j<20 && (!dirEnable[dir] || (((type == 1) ^ (nexts[now].dir[dir] == -1)) && !invalidOpEnable[type - 1]));j++)
					dir = rnd.next(0,3);

				if(!dirEnable[dir] || (((type == 1) ^ (nexts[now].dir[dir] == -1)) && !invalidOpEnable[type - 1])) {
					i--;
					continue;
				}
			}

			int val = -1;
			if(type == 1 || type == 3)	val = rnd.next(0,1000000000);
		
			ops.push_back(op{type,dir,val});
		
			if(type == 1) {
				if(nexts[now].dir[dir] == -1) {
					nexts[now].dir[dir] = cnt;
					nexts[cnt].dir[(dir + 2) % 4] = now;

					cnt++;
				}
			}
			else if(type == 2) {
				if(nexts[now].dir[dir] != -1)
					now = nexts[now].dir[dir];
			}
		}

		if(testNumber == 9) {
			Q++;
			ops.push_back(op{4,-1,-1});
		}
	}

	cout << Q << '\n';
	for(op now : ops) {
		cout << now.type;
		if(now.type == 1)
			cout << " " << now.dir << " " << now.val;
		else if(now.type == 2)
			cout << " " << now.dir;
		else if(now.type == 3)
			cout << " " << now.val;
		cout << '\n';
	}
	return 0;
}
