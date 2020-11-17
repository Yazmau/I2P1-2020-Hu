// TLE, O(2^{n^2}n^3) by Yazmau
#include<bits/stdc++.h>
#define maxn 15
#define INF 12345678912345ll
using namespace std;
int arr[maxn][maxn];
bool vis[maxn][maxn];
long long sol(int x,int y,int n) {
	if(x == n) {
		int dx[] = {-1,0,0,1,1}, dy[] = {0,-1,1,-1,1};
		long long ret = 0, cnt = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(vis[i][j]) {
					ret += arr[i][j];
					cnt++;
					for(int type=0;type<5;type++) {
						int nx = i + dx[type], ny = j + dy[type];
						while(0 <= nx && nx < n && 0 <= ny && ny < n) {
							if(vis[nx][ny])	return -INF;
							nx += dx[type], ny += dy[type];
						}
					}
				}
		return cnt == n ? ret : -INF;
	}
	else {
		int nx = x, ny = y + 1;
		if(ny == n)	nx++, ny = 0;
		long long ret = -INF;

		ret = max(ret, sol(nx,ny,n));
		vis[x][y] = true;
		ret = max(ret, sol(nx,ny,n));
		vis[x][y] = false;

		return ret;
	}
}
int main() {
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> arr[i][j];
	long long ans =	sol(0,0,n);
	if(ans == -INF)
		cout << "no solution" << endl;
	else
		cout << ans << endl;
	return 0;
}
