/*
2 <= n <= 20
0 <= m, w_i, v_i <= 1000
q = 1
1 <= a_i < b_i <= n
w_{a_1} = v_{a_1} = w_{b_1} = w_{b_2} = 0
*/
#include "../testlib.h"
using namespace std;
int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	int n = inf.readInt(1, 20, "n");
	inf.readSpace();
	int m = inf.readInt(0, 1000000000, "m");
	inf.readEoln();

	vector<int> weight,value;
	for(int i=1;i<=n;i++) {
		int w = inf.readInt(0, 1000000000, "w");
		inf.readSpace();
		int v = inf.readInt(0, 1000000000, "v");
		inf.readEoln();

		weight.push_back(w);
		value.push_back(v);
	}

	int q = inf.readInt(1, 1, "q");
	inf.readEoln();

	for(int i=1;i<=q;i++) {
		int a = inf.readInt(1, n, "a");
		inf.readSpace();
		int b = inf.readInt(a + 1, n, "b");
		inf.readEoln();
		
		ensuref(weight[a - 1] == 0 && value[a - 1] == 0 && weight[b - 1] == 0 && value[b - 1] == 0, "w_{a_1} = v_{a_1} = w_{b_1} = w_{b_2} = 0");
	}

	inf.readEof();
	return 0;
}
