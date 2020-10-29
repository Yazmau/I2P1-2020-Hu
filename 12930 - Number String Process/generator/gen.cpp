#include "../testlib.h"
using namespace std;
struct que {
	int a,b,sz;
};
struct op {
	int A,B,sz;
};
int genSpecificDigitNumber(int digit) {
	int ret = 0;
	for(int i=0;i<digit;i++)
		ret = ret * 10 + rnd.next(1,9);
	return ret;
}
op genOp(int maxSz,long long maxAns) {
	while(true) {
		int sz = rnd.next(1,maxSz);
		int A = genSpecificDigitNumber(sz), B = genSpecificDigitNumber(sz);
		if((long long)A * B <= maxAns) {
			return op{A,B,sz};
		}
	}
}
int calDigit(long long val) {
	int ret = 0;
	while(val > 0) {
		ret++;
		val /= 10;
	}
	return ret;
}
vector<op> genOps(int n,long long maxAns) {
	vector<op> ret;

	ret.push_back(op{(int)sqrt(maxAns),(int)sqrt(maxAns),(int)calDigit(sqrt(maxAns))});
	int totSz = ret.back().sz * 2;
	while(n - totSz > max(1,n / 100)) {
		int nowMaxSz = min(9, (n - totSz) / 2);
		ret.push_back(genOp(nowMaxSz,maxAns));
		totSz += ret.back().sz * 2;
	}

	shuffle(ret.begin(),ret.end());
	return ret;
}
string toString(int val) {
	string ret = "";
	while(val > 0) {
		ret += (char)('0' + val % 10);
		val /= 10;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
tuple<string, vector<que> > tranOpsToProblemForm(vector<op> ops,int n,bool adjAndBack) {
	string s = "";
	vector<que> ques;

	int totSz = 0;
	for(op now : ops)	totSz += now.sz * 2;
	for(int i=totSz;i<n;i++)	s += (char)('0' + rnd.next(1,9));
	totSz = (int)s.size();

	for(op now : ops) {
		string A = toString(now.A), B = toString(now.B);
		int sz = now.sz;
		
		int a,b;
		if(adjAndBack)
			a = totSz, b = totSz + sz;
		else
			a = rnd.next(0,totSz) , b = rnd.next(a,totSz) + sz;
		
		s.insert(a,A);
		s.insert(b,B);
		ques.push_back(que{a,b,sz});
		totSz += sz * 2;
	}
	reverse(ques.begin(),ques.end());

	return make_tuple(s, ques);
}
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int testnum = atoi(argv[1]);

	int n = -1;

	if(testnum == 1)	n = 9;
	else if(testnum == 2)	n = 99;
	else if(testnum == 3)	n = 499;
	else	n = 1000;

	// ensure sqrt(maxAns) doesn't have any zero
	long long _maxAns[] = {9,99999999,99999999,99999999,99999999,999999999,2000000000,4000000000ll,9999999999ll,(1ll<<60-4)};
	long long maxAns = _maxAns[testnum - 1];

	vector<op> ops = genOps(n,maxAns);	
	auto [s, ques] = tranOpsToProblemForm(ops,n,testnum <= 4);

	cout << n << '\n';
	cout << s << '\n';
	cout << (int)ques.size() << '\n';
	for(que now : ques)
		cout << now.a << " " << now.b << " " << now.sz << '\n';
	return 0;
}
