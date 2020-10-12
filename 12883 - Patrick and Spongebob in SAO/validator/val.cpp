/*
1 <= n,arr_i <= 500
1 <= l <= r <= n
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	// input n
	int n = inf.readInt(1, 500, "n");
	inf.readEoln();

	// input array
	vector<int> arr = inf.readInts(n, 1, 500, "arr");
	inf.readEoln();

	// input q
	int q = inf.readInt(1, 500, "q");
	inf.readEoln();

	// input query
	for(int i=1;i<=q;i++) {
		int l = inf.readInt(1, n, "left bound for query");
		inf.readSpace();
		int r = inf.readInt(l, n, "right bound for query");
		inf.readEoln();
	}

	inf.readEof();
	return 0;
}
