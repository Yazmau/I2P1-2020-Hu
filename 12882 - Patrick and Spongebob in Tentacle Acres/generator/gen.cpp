#include "../testlib.h"
using namespace std;
struct que {
	int u,d,l,r;
};
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int subtask = atoi(argv[1]);

	int n = -1, m = -1, q = -1;
	vector<vector<int> > arr;
	vector<que> ques;

	if(subtask == 1 || subtask == 2)
		n = 1;
	else
		n = rnd.next(1,100);
	m = rnd.next(1,100);
	for(int i=1;i<=n;i++) {
		vector<int> temp;
		for(int j=1;j<=m;j++)
			temp.push_back((subtask == 1 ? 1 : rnd.next(1,100)));
		arr.push_back(temp);
	}
	q = rnd.next(1,100);
	for(int i=1;i<=q;i++) {
		int u = rnd.next(1,n);
		int d = rnd.next(u,n);
		int l = rnd.next(1,m);
		int r = rnd.next(l,m);
		ques.push_back(que{u,d,l,r});
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
	for(int i=0;i<q;i++)
		cout << ques[i].u << " " << ques[i].d << " " << ques[i].l << " " << ques[i].r << '\n';
	return 0;
}
