// solution with O(2^m x nm) by Yazmau
#include<bits/stdc++.h>
#define maxn 25
using namespace std;
int n,m;
bool state[maxn][maxn];
void update(int i,int j) {
	static int delta_i[] = {0,-1,0,1,0};
	static int delta_j[] = {0,0,-1,0,1};
	for(int t=0;t<5;t++) {
		int now_i = i + delta_i[t];
		int now_j = j + delta_j[t];
		state[now_i][now_j] = !state[now_i][now_j];
	}
}
int solve(int pos,int sum) {
	int ret = -1;
	if(pos == m + 1) {
		queue<pair<int,int> > undo;
		for(int i=2;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(state[i - 1][j]) {
					update(i,j);
					sum++;
					undo.push({i,j});
				}
				
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(state[i][j])
					sum = -1;
		ret = sum;
		
		while(!undo.empty()) {
			auto now = undo.front();
			undo.pop();
			update(now.first, now.second);
		}
	}
	else {
		for(auto s : {false,true}) {
			if(s)	update(1,pos);
			int now = solve(pos + 1, sum + (s ? 1 : 0));
			if(now != -1 && (ret == -1 || now < ret))	ret = now;
			if(s)	update(1,pos);
		}
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1,s;j<=m;j++)
			cin >> s, state[i][j] = !s;
	int ans = solve(1,0);
	if(ans == -1)
		cout << "no solution" << endl;
	else
		cout << ans << endl;
	return 0;
}
