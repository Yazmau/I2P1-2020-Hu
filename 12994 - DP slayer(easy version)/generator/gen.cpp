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
	
	const int MAXV = 1e9;
	
	vector<obj> objs;
	vector<que> ques;

	int n = 20;
	int m = 1000000000;
	int q = 1;

	if(testnum == 1) {	// like sample
		n = 8;
		m = 16;
		objs = {obj{0,0},obj{6,6},obj{4,87},obj{6,7},obj{5,6},obj{0,0},obj{7,7},obj{8,4}};
		ques = {que{1,6}};
	}
	else {
		if(testnum == 2) {	// cp-value-greedy
			objs = {obj{4,0},obj{MAXV,MAXV / 100},obj{0,0},obj{0,0}};
			int baseW = m / (n - (int)objs.size());
			for(int i=(int)objs.size();i<n;i++) {
				int w = baseW;
				int v = rnd.next(MAXV / 10 / 100,MAXV / 100);
				objs.push_back(obj{w,v});
			}
		}
		else if(testnum == 3) {	// cp-value-greedy with overflow
			objs = {obj{5,0},obj{MAXV,MAXV},obj{0,0},obj{0,0},obj{MAXV,1},obj{MAXV,1}};
			int baseW = m / (n - (int)objs.size());
			for(int i=(int)objs.size();i<n;i++) {
				int w = baseW;
				int v = rnd.next(MAXV / 10,MAXV);
				objs.push_back(obj{w,v});
			}
		}
		else {
			m /= 100;
			objs = {obj{100,1},obj{0,0},obj{0,0},obj{0,87}};
			{
				int num = testnum - 4 + 1;
				int w = m / (num + 1) + 1;
				int v = MAXV;
				for(int i=0;i<num;i++)
					objs.push_back(obj{w,v});
			}
			{
				int num = testnum - 4 + 2;
				int w = m / num;
				int v = w * (objs.back().v / objs.back().w - 1);
				for(int i=0;i<num;i++)
					objs.push_back(obj{w,v});
			}
			for(int i=(int)objs.size();i<n;i++) {
				int w = rnd.next(m % objs[4].w + 1,MAXV);
				int v = rnd.next(0,MAXV / 1000);
				objs.push_back(obj{w,v});
			}
		}
		shuffle(objs.begin(),objs.end());
		int a = -1, b = -1;
		for(int i=0;i<n;i++)
			if(objs[i].w == 0 && objs[i].v == 0) {
				if(a == -1)
					a = i + 1;
				else
					b = i + 1;
			}
		ques = {que{a,b}};
	}

	cout << n << " " << m << '\n';
	for(obj now : objs)
		cout << now.w << " " << now.v << '\n';
	cout << q << '\n';
	for(que now : ques)
		cout << now.a << " " << now.b << '\n';
	return 0;
}
