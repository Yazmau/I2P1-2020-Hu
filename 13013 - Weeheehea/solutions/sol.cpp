// solution by Yazmau
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	set<string> strSet;
	for(int i=0;i<n;i++)
		cin >> s, strSet.insert(s);
	cout << (int)strSet.size() << endl;
	return 0;
}
