/*
1 <= N <= 10^5
0 <= K <= 9
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int N = inf.readInt(1, 100000, "N");
	inf.readSpace();
	int K = inf.readInt(0, 10, "K");
	inf.readEoln();
		
	for(int i=0;i<N+1;i++) {
		int xCnt = 0;
		for(int j=0;j<3;j++) {
			string s = inf.readLine();
			inf.ensuref((int)s.size() == 3, "the length of each row of A(B) must be 3");
			for(char c : s) {
				inf.ensuref(c == '0' || c == '1' || c == 'x', "A(B) must contain only 0, 1 or x");
				xCnt += (int)(c == 'x');
			}
		}
		inf.ensuref(xCnt == 1, "there must be exactly one x in A(B)");
	}

	inf.readEof();
	return 0;
}
