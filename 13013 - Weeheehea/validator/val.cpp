/*
1 <= N <= 10^5
| S_i | = 10
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int N = inf.readInt(1, 100000, "N");
	inf.readEoln();
	
	for(int i=1;i<=N;i++) {
		string S = inf.readLine();
		inf.ensuref((int)S.size() == 10, "the length of S must be 10");
		int xCnt = 0;
		for(char c : S) {
			inf.ensuref(c == '0' || c == '1' || c == 'x', "S must contain only 0, 1 or x");
			xCnt += (int)(c == 'x');
		}
		inf.ensuref(xCnt == 1, "there must be exactly one x in S");
	}

	inf.readEof();
	return 0;
}
