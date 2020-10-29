/*
1 <= n,q <= 1000
'1' <= s_i <= '9'
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	// input n
	int n = inf.readInt(1, 1000, "n");
	inf.readEoln();

	// input s
	string s = inf.readWord();
	inf.readEoln();
	ensuref((int)s.size() == n, "Length of s is not equal to n");
	for(char c : s)
		ensuref('1' <= c && c <= '9', "There is an element not in [1,9] in s");

	// input q
	int q = inf.readInt(1, 1000, "q");
	inf.readEoln();

	// input each query
	for(int i=0;i<q;i++) {
		int a = inf.readInt(0,1000,"a");
		inf.readSpace();
		int b = inf.readInt(0,1000,"b");
		inf.readSpace();
		int sz = inf.readInt(1,1000,"sz");
		inf.readEoln();

		ensuref(0 <= a && a + sz <= b && b + sz <= n,"Intervals of A and B are incorrect");
		n = n - sz - sz;
	}

	inf.readEof();
	return 0;
}
