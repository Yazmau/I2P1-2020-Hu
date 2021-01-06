/*
1 <= N, Q <= 5 * 10^5
0 <= a_i <= 10^9
1 <= type <= 3
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int N = inf.readInt(1, 500000, "N");
	inf.readEoln();

	const int MINV = 0, MAXV = 1000000000;

	vector<int> arr = inf.readInts(N, MINV, MAXV, "arr");
	inf.readEoln();

	int Q = inf.readInt(1, 500000, "Q");
	inf.readEoln();

	int pos = 1;
	for(int i=0;i<Q;i++) {
		int type = inf.readInt(1, 3, "type");
		if(type == 1) {
			inf.readSpace();
			int dir = inf.readInt(-1, 1, "dir");
			inf.ensuref(dir == -1 || dir == 1, "dir must be -1 or 1");
			
			pos += dir;
			inf.ensuref(1 <= pos && pos <= N, "cannot move outside");
		}
		else if(type == 3) {
			if(pos > (N + 1) / 2)	pos--;
			N--;
			inf.ensuref(N >= 1, "there must be at most N - 1 the 3-rd-type operations");
		}
		inf.readEoln();
	}
	
	inf.readEof();
	return 0;
}
