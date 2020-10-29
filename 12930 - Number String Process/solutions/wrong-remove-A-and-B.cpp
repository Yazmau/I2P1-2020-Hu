// by Yazmau
#include<bits/stdc++.h>
using namespace std;
int stringToInt(string s) {
	int ret = 0;
	for(char c : s)	ret = ret * 10 + c - '0';
	return ret;
}
int main() {
	int n,q;
	string s;
	cin >> n >> s >> q;
	while(q--) {
		int a,b,sz;
		cin >> a >> b >> sz;
		string strA = s.substr(a,sz), strB = s.substr(b,sz);
		int A = stringToInt(strA), B = stringToInt(strB);
		cout << (long long)A * B << endl;
		s.erase(b,sz);
		s.erase(a,sz);
	}
	return 0;
}
