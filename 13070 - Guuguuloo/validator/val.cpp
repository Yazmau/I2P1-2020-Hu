/*
1 <= N, Q <= 10^5
1 <= A_i, x_i, y_i <= 10^9
x_i is increasing
y_i is increasing
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int N = inf.readInt(1, 100000, "N");
	inf.readEoln();

	const int MAXV = 1000000000;
	inf.readInts(N, 1, MAXV, "arr");
	inf.readEoln();

	int Q = inf.readInt(1, 100000, "Q");
	inf.readEoln();

	int preX = 1, preY = 1;
	for(int i=0;i<Q;i++) {
		int type = inf.readInt(1, 2, "type");
		inf.readSpace();
		
		if(type == 1) {
			int x = inf.readInt(preX, MAXV, "x");
			preX = x;
		}
		else {
			int y = inf.readInt(preY, MAXV, "y");
			preY = y;
		}
		inf.readEoln();
	}
	
	inf.readEof();
	return 0;
}
