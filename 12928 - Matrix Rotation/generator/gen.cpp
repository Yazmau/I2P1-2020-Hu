#include "../testlib.h"
using namespace std;
struct que {
	int u,d,l,r;
};
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int testnum = atoi(argv[1]);

	int MAXV = 1000000000;
	int _n[] = {2,2,2,2,5,90,100,93,95,96};
	int _m[] = {2,2,2,2,5,100,99,90,87,98};
	int _q[] = {1,2,3,4,101,102,MAXV,MAXV - 1,MAXV - 2,MAXV - 3};

	int n = _n[testnum - 1], m = _m[testnum - 1], q = _q[testnum - 1];

	vector<vector<int> > arr;
	if(testnum <= 4) {
		int val[] = {1,2,3,4};
		shuffle(val,val+4);
		arr = {{val[0],val[1]},{val[2],val[3]}};
	}
	else {
		vector<int> val;
		int sz = rnd.next(1,n * m);
		for(int i=0;i<sz;i++)	val.push_back(rnd.next(1,MAXV));
		sz = (int)val.size();

		for(int i=0;i<n;i++) {
			vector<int> row;
			for(int j=0;j<m;j++)
				row.push_back(val[rnd.next(sz)]);
			arr.push_back(row);
		}
	}

	cout << n << " " << m << '\n';
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(j != 0)	cout << " ";
			cout << arr[i][j];
		}
		cout << '\n';
	}
	cout << q << '\n';
	return 0;
}
