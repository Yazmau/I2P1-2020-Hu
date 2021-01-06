/*
1 <= N <= 10^5
1 <= A_i <= 10^5
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int N = inf.readInt(1, 100000, "N");
	inf.readEoln();
	
	inf.readInts(N, 1, 100000, "A");
	inf.readEoln();
	
	inf.readEof();
	return 0;
}
