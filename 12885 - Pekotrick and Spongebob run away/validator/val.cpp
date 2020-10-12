/*
1 <= n,m <= 500, 2 | m
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int n = inf.readInt(1, 500, "n");
	inf.readSpace();
	int m = inf.readInt(1, 500, "m");
	ensuref((m % 2 == 0), "m must be even");
	inf.readEoln();

	inf.readEof();
	return 0;
}
