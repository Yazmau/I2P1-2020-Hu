/*
1 <= n <= 10
| a_{ij} | <= 10^9
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int n = inf.readInt(1, 10, "n");
	inf.readEoln();

	const int MAXV = 1000000000;
	for(int i=0;i<n;i++) {
		vector<int> row = inf.readInts(n, -MAXV, MAXV, "a");
		inf.readEoln();
	}

	inf.readEof();
	return 0;
}
