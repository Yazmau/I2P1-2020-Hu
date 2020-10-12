/*
1 <= n <= 250
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int n = inf.readInt(1, 250, "n");
	inf.readEoln();
	inf.readEof();
	return 0;
}
