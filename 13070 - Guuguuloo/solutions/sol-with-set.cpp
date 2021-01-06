// solution with std::set by Yazmau
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	set<int> s;
	for(int i=1,val;i<=N;i++)
		cin >> val, s.insert(val);
	int Q;
	cin >> Q;
	while(Q--) {
		int type,val;
		cin >> type >> val;
		if(type == 1) {
			if(s.count(val) == 1)	s.erase(val);
		}
		else
			cout << (s.count(val) == 1 ? "Yes" : "No") << '\n';
	}
	return 0;
}
