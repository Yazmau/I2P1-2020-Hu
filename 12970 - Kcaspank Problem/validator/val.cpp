/*
1 <= n <= 20
1 <= m, weight_i <= 1000
1 <= value_i <= 10^9
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int n = inf.readInt(1, 20, "n");
	inf.readSpace();
	int m = inf.readInt(1, 1000, "m");
	inf.readEoln();

	for(int i=1;i<=n;i++) {
		int weight = inf.readInt(1, 1000, "weight");
		inf.readSpace();
		int value = inf.readInt(1, 1000000000, "value");
		inf.readEoln();
	}

	inf.readEof();
	return 0;
}
