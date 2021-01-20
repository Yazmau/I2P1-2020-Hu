/*
1 <= N, Q <= 10^5
0 <= a_i <= 10^18
1 <= type <= 2
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int N = inf.readInt(1, 100000, "N");
	inf.readEoln();

	const long long MINV = 0, MAXV = (long long)1e18;

	vector<long long> arr = inf.readLongs(N, MINV, MAXV, "arr");
	inf.readEoln();

	int Q = inf.readInt(1, 100000, "Q");
	inf.readEoln();

	for(int i=0;i<Q;i++) {
		int type = inf.readInt(1, 2, "type");
		if(type == 1) {
			N--;
			inf.ensuref(N >= 1, "there must be at most N - 1 the 3-rd-type operations");
		}
		else {
			inf.readSpace();
			int k = inf.readInt(1, N, "k");
		}
		inf.readEoln();
	}
	
	inf.readEof();
	return 0;
}
