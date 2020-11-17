/*
1 <= n * m <= 20
0 <= a_ij <= 1
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int n = inf.readInt(1, 20, "n");
	inf.readSpace();
	int m = inf.readInt(1, 20, "m");
	inf.readEoln();
	ensuref(n * m <= 20, "n * m > 20");

	for(int i=1;i<=n;i++) {
		vector<int> row = inf.readInts(m, 0, 1, "row");
		inf.readEoln();
	}

	inf.readEof();
	return 0;
}
