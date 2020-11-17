#include "../testlib.h"
using namespace std;
struct obj {
	int w,v;
};
struct que {
	int a,b;
};
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int testnum = atoi(argv[1]);
	
	vector<obj> objs;
	vector<que> ques;

	int _n[] = {6,10,15,17,20};
	int _q[] = {3,100,300,100000,100000};

	int n = _n[testnum - 1];
	int m = 1e9;
	int q = _q[testnum - 1];

	if(testnum == 1) {	// like sample
		m = 9;
		objs = {obj{6,12},obj{4,7},obj{4,7},obj{0,87},obj{1,0},obj{2,1}};
		ques = {que{4,5},que{1,2},que{5,6}};
	}
	else {
		int MAXV = (testnum & 1) ? 1e9 : 1e8;
		if(~testnum & 1)	m = 1e8;
		
		objs = {obj{1,0}};

		for(int i=0;i<3;i++) {
			int w = m / 4 + 1;
			int v = MAXV;
			objs.push_back({w,v});
		}
		
		for(int i=0;i<4;i++) {
			int w = m / 4;
			int v = objs[1].v - rnd.next(87,870);
			objs.push_back(obj{w,v});
		}
		
		
		for(int i=(int)objs.size();i<n;i++) {
			int w = rnd.next(1,10);
			int v = rnd.next(1,10);
			objs.push_back(obj{w,v});
		}
		
		shuffle(objs.begin(),objs.end());
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ques.push_back(que{i,j});
		for(int i=(int)ques.size();i<q;i++) {
			int a = rnd.next(1,n - 1);
			int b = rnd.next(a + 1,n);
			ques.push_back(que{a,b});
		}
	}

	cout << n << " " << m << '\n';
	for(obj now : objs)
		cout << now.w << " " << now.v << '\n';
	cout << q << '\n';
	for(que now : ques)
		cout << now.a << " " << now.b << '\n';
	return 0;
}
