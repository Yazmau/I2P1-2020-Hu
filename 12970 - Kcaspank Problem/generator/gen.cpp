#include "../testlib.h"
using namespace std;
struct obj {
	int weight,value;
};
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int testnum = atoi(argv[1]);
	
	int _n[] = {6,8,8,8,20,20,20,20,20,20};
	vector<obj> objs;
	
	int n = _n[testnum - 1];
	int m = 1000;
	
	const int MAXV = 1e9;
	if(testnum == 1) {	// sample
		m = 16;
		objs = {obj{6,6},obj{4,9},obj{6,7},obj{5,6},obj{7,7},obj{8,4}};
	}
	else {
		if(testnum == 2) {	// weight-greedy
			objs = {obj{501,MAXV / 10},obj{409,MAXV / 10}};
			for(int i=2;i<n;i++) {
				int w = rnd.next(1,200);
				int v = rnd.next(MAXV / 20, MAXV / 10);
				objs.push_back(obj{w,v});
			}
		}
		else if(testnum == 3) {	// value-greedy
			objs = {obj{500,MAXV / 10},obj{500,MAXV / 10}};
			for(int i=2;i<n;i++) {
				int w = rnd.next(1,250);
				int v = rnd.next(1,MAXV / 20 - 5);
				objs.push_back(obj{w,v});
			}
		}
		else if(testnum == 4) {	// cp-value-greedy
			objs = {obj{4,4},obj{1000,1000}};
			for(int i=2;i<n;i++) {
				int w = 166;
				int v = rnd.next(200,300);
				objs.push_back(obj{w,v});
			}
		}
		else if(testnum == 5) {	// just random without overflow
			m = rnd.next(1,1000);
			for(int i=0;i<n;i++) {
				int w = rnd.next(1,1000);
				int v = rnd.next(1,MAXV / 10);
				objs.push_back(obj{w,v});
			}
		}
		else if(testnum == 6) {	// 3 greedy but overflow
			obj base = obj{50,MAXV / 5};
			for(int i=0;i<n;i++)
				objs.push_back(base);
		}
		else {
			objs = {obj{100,1}};
			{
				int num = testnum - 7 + 1;
				int w = m / (num + 1) + 1;
				int v = MAXV;
				for(int i=0;i<num;i++)
					objs.push_back(obj{w,v});
			}
			{
				int num = testnum - 7 + 2;
				int w = m / num;
				int v = w * (objs.back().value / objs.back().weight - 1);
				for(int i=0;i<num;i++)
					objs.push_back(obj{w,v});
			}
			for(int i=(int)objs.size();i<n;i++) {
				int w = rnd.next(m % objs[1].weight + 1,1000);
				int v = rnd.next(1,MAXV);
				objs.push_back(obj{w,v});
			}
		}
		shuffle(objs.begin(),objs.end());
	}

	cout << n << " " << m << '\n';
	for(obj now : objs)
		cout << now.weight << " " << now.value << '\n';
	return 0;
}
