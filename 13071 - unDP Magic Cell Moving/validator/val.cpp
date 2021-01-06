/*
1 <= Q <= 10^5
1 <= type_i <= 4
0 <= v_i <= 10^9
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int Q = inf.readInt(1, 100000, "Q");
	inf.readEoln();

	for(int i=0;i<Q;i++) {
		int type = inf.readInt(1, 6, "type");
		if(type == 1) {
			inf.readSpace();
			int dir = inf.readInt(0, 3, "dir");
			inf.readSpace();
			int val = inf.readInt(0, 1000000000, "val");
		}
		else if(type == 2) {
			inf.readSpace();
			int dir = inf.readInt(0, 3, "dir");
		}
		else if(type == 3) {
			inf.readSpace();
			int val = inf.readInt(0, 1000000000, "val");
		
		}
		inf.readEoln();
	}
	
	inf.readEof();
	return 0;
}
