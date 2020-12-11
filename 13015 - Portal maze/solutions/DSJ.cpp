// WA, with DSJ by Yazmau
#include<bits/stdc++.h>
#define maxn 305
using namespace std;
int pa[maxn*maxn];
int Find(int x) {
	return pa[x] == x ? x : pa[x] = Find(pa[x]);
}
void Union(int x,int y) {
	pa[Find(x)] = Find(y);
}
string s[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n,m;
		cin >> n >> m;
		map<char,pair<int,int> > pos;
		for(int i=0;i<n;i++) {
			cin >> s[i];
			for(int j=0;j<m;j++)
				if(s[i][j] != '#' && s[i][j] != '.')
					pos[s[i][j]] = {i,j};
		}
		iota(pa,pa + n * m,0);
		int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(s[i][j] != '#')
					for(int dir=0;dir<4;dir++) {
						int new_i = i + dx[dir], new_j = j + dy[dir];
						if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m || s[new_i][new_j] == '#')	continue;
						int u = i * m + j, v = new_i * m + new_j;
						if(Find(u) != Find(v))	Union(u,v);
					}
		for(char c='a';c<='z';c++)
			if(pos.find(c) != pos.end()) {
				auto lower = pos[c], upper = pos[toupper(c)];
				int u = lower.first * m + lower.second, v = upper.first * m + upper.second;
				if(Find(u) != Find(v))	Union(u,v);
			}
		cout << (Find(pos['$'].first * m + pos['$'].second) == Find(pos['&'].first * m + pos['&'].second) ? "Yes" : "No") << endl;
	}
	return 0;
}
