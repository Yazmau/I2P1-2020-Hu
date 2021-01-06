/*
1 <= Q <= 10^5
1 <= type_i <= 6
0 <= v_i <= 10^9
*/
#include "../testlib.h"
using namespace std;
struct nxt {
	int dir[4];
	nxt() {
		dir[0] = dir[1] = dir[2] = dir[3] = -1;
	}
};
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int Q = inf.readInt(1, 100000, "Q");
	inf.readEoln();

	int now = 0, cnt = 1;
	vector<nxt> nexts(Q + 5);
	int portal = 0;

	for(int i=0;i<Q;i++) {
		int type = inf.readInt(1, 6, "type");
		if(type == 1) {
			inf.readSpace();
			int dir = inf.readInt(0, 3, "dir");
			inf.readSpace();
			int val = inf.readInt(0, 1000000000, "val");
			inf.ensuref(nexts[now].dir[dir] == -1, "placement is invalid");
			
			nexts[now].dir[dir] = cnt;
			nexts[cnt].dir[(dir + 2) % 4] = now;

			cnt++;
		}
		else if(type == 2) {
			inf.readSpace();
			int dir = inf.readInt(0, 3, "dir");
			inf.ensuref(nexts[now].dir[dir] != -1, "movement is invalid");

			now = nexts[now].dir[dir];
		}
		else if(type == 3) {
			inf.readSpace();
			int val = inf.readInt(0, 1000000000, "val");
		}
		else if(type == 5) {
			portal = now;
		}
		else if(type == 6) {
			now = portal;
		}
		inf.readEoln();
	}
	
	inf.readEof();
	return 0;
}
