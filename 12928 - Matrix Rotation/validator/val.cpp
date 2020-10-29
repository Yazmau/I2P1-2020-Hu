/*
1 <= n,m <= 100
1 <= a_{ij}, q <= 10^9
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	// input n,m
	int n = inf.readInt(1, 100, "n");
	inf.readSpace();
	int m = inf.readInt(1, 100, "m");
	inf.readEoln();

	// input matrix
	for(int i=1;i<=n;i++) {
		vector<int> arr = inf.readInts(m, 1, 1000000000, "mat");
		inf.readEoln();
	}

	// input q
	int q = inf.readInt(1, 1000000000, "q");
	inf.readEoln();

	inf.readEof();
	return 0;
}
