// WA, wrong BFS by Yazmau
#include<bits/stdc++.h>
using namespace std;
string move(string s,int dir) {
	static int delta[] = {-1,1,-3,3};
	int pos = s.find("x"), new_pos = pos + delta[dir];
	if(new_pos < 0 || new_pos > 8)	return "error";
	swap(s[pos],s[new_pos]);
	return s;
}
int main() {
	int T;
	cin >> T;
	while(T--) {
		int k;
		cin >> k;
		string A = "", B = "";
		for(string *s : {&A,&B}) {
			string temp;
			for(int i=0;i<3;i++)
				cin >> temp, (*s) += temp;
		}
		string ans = "No";
		
		set<string> vis;
		queue<pair<string,int> > q;
		q.push({A,0});
		vis.insert(A);

		while(!q.empty()) {
			auto now = q.front();	q.pop();
			string s = now.first;
			int dep = now.second;
			if(s == B) {
				ans = "Yes";
				break;
			}
			if(dep == k)	continue;
			for(int i=0;i<4;i++) {
				string nxt = move(s,i);
				if(nxt != "error" && vis.count(nxt) == 0) {
					q.push({nxt,dep + 1});
					vis.insert(nxt);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
