#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	set<string> s;
	int need = -1;
	for(int i=0;i<=n;i++) {
		string str = "", now;
		for(int j=0;j<3;j++)
			cin >> now, str += now;
		int cnt = 0;
		for(char c : str)	if(c == '1')	cnt++;
		if(need == -1)
			need = cnt;
		if(need == cnt)
			s.insert(str);
	}
	cout << (int)s.size() << endl;
	return 0;
}

