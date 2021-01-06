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
		Q = 14;
		ops = {op{1,0,5},op{2,0,-1},op{4,-1,-1},op{3,-1,6},op{4,-1,-1},op{6,-1,-1},op{4,-1,-1},
					op{1,1,0},op{2,1,-1},op{5,-1,-1},op{2,3,-1},op{2,0,-1},op{6,-1,-1},op{4,-1,-1}};
	}
	else {
		Q = (testNumber <= 7 ? 1000 : 100000);
		bool dirEnable[4] = {true,true,true,true};
		bool opEnable[6] = {true,true,true,true,true,true};

		if(testNumber <= 7) {
			fill(dirEnable,dirEnable + 4,false);
			if(testNumber <= 5)
				dirEnable[testNumber - 2] = true;
			else
				dirEnable[testNumber - 6] = dirEnable[testNumber - 6 + 2] = true;
		}
		else if(testNumber == 8)
			opEnable[3 - 1] = false;
		else if(testNumber == 9)
			opEnable[5 - 1] = opEnable[6 - 1] = false;

		int now = 0, portal = 0, cnt = 1;
		vector<nxt> nexts(Q + 5);
		
		for(int i=0;i<Q;i++) {
			int type = rnd.next(1,6);
			while(!opEnable[type - 1])	type = rnd.next(1,6);
			
			int dir = -1;
			if(type == 1 || type == 2) {
				dir = rnd.next(0,3);
				for(int j=0;j<10 && (!dirEnable[dir] || ((type == 1) ^ (nexts[now].dir[dir] == -1)));j++)
					dir = rnd.next(0,3);

				if(!dirEnable[dir] || ((type == 1) ^ (nexts[now].dir[dir] == -1))) {
					i--;
					continue;
				}
			}

			int val = -1;
			if(type == 1 || type == 3)	val = rnd.next(0,1000000000);
		
			ops.push_back(op{type,dir,val});
		
			if(type == 1) {
				nexts[now].dir[dir] = cnt;
				nexts[cnt].dir[(dir + 2) % 4] = now;

				cnt++;
			}
			else if(type == 2) {
				now = nexts[now].dir[dir];
			}
			else if(type == 5) {
				portal = now;
			}
			else if(type == 6) {
				now = portal;
			}
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
