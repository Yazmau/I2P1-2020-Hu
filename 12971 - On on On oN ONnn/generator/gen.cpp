#include "../testlib.h"
#include <numeric>
using namespace std;
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int testnum = atoi(argv[1]);

	int _n[] = {3,4,4,4,20,1,5,4,4,5};
	int _m[] = {3,4,4,4,1,20,4,5,5,4};
	int _num[] = {-1,3,13,16,5,17,6,8,10,12};
	int _init[] = {-1,1,0,1,1,0,1,1,1,1};

	int n = _n[testnum - 1], m = _m[testnum - 1];
	vector<vector<int> > arr;

	if(testnum == 1) {
		arr = {
			{0,0,1},
			{0,0,0},
			{0,1,1}
		};
	}
	else {
		int init = _init[testnum - 1];
		for(int i=0;i<n;i++) {
			vector<int> row(m,init);
			arr.push_back(row);
		}

		vector<int> idxs(n*m);
		iota(idxs.begin(),idxs.end(),0);
		shuffle(idxs.begin(),idxs.end());
		
		int num = _num[testnum - 1];
		for(int i=0;i<num;i++) {
			int idx = idxs[i];
			int x = idx / m, y = idx % m;
			if(init == 0) {
				arr[x][y] = 1;
			}
			else {
				int dx[] = {0,-1,0,0,1}, dy[] = {0,0,-1,1,0};
				for(int j=0;j<5;j++) {
					int nx = x + dx[j], ny = y + dy[j];
					if(nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;
					arr[nx][ny] ^= 1;
				}
			}
		}
	}

	cout << n << " " << m << '\n';
	for(auto row : arr) {
		for(int i=0;i<m;i++) {
			if(i != 0)	cout << " ";
			cout << row[i];
		}
		cout << '\n';
	}
	return 0;
}
