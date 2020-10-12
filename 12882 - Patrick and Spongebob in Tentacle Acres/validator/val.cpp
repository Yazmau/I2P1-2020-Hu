/*
1 <= n,m,arr_{ij},q <= 100
1 <= u <= d <= n
1 <= l <= r <= m
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
		vector<int> arr = inf.readInts(m, 1, 100, "arr");
		inf.readEoln();
	}

	// input q
	int q = inf.readInt(1, 100, "q");
	inf.readEoln();

	// input query
	for(int i=1;i<=q;i++) {
		vector<int> row = inf.readInts(2, 1, n, "query_row_bound");
		ensuref(row[0] <= row[1], "u < d in query");
		inf.readSpace();
		vector<int> col = inf.readInts(2, 1, m, "query_column_bound");
		ensuref(col[0] <= col[1], "l > r in query");
		inf.readEoln();
	}

	inf.readEof();
	return 0;
}
