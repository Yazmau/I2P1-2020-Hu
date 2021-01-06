/*
1 <= N, Q <= 10^5
-2*10^9 <= A_i, x_i < 2*10^9
x_i is decreasing
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int N = inf.readInt(1, 100000, "N");
	inf.readEoln();

	const int MINV = -2000000000, MAXV = 2000000000;

	vector<int> arr = inf.readInts(N, MINV, MAXV, "arr");
	inf.readEoln();

	int Q = inf.readInt(1, 100000, "Q");
	inf.readEoln();

	int preX = MAXV;
	for(int i=0;i<Q;i++) {
		int x = inf.readInt(MINV, preX, "x");
		preX = x;
		
		inf.readEoln();
	}
	
	inf.readEof();
	return 0;
}
