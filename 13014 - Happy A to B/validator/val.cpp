/*
1 <= T <= 10
0 <= K <= 9
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int T = inf.readInt(1, 10, "T");
	inf.readEoln();

	for(int t=0;t<T;t++) {
		int K = inf.readInt(0, 9, "K");
		inf.readEoln();

		for(int i=0;i<2;i++) {
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
	}

	inf.readEof();
	return 0;
}
