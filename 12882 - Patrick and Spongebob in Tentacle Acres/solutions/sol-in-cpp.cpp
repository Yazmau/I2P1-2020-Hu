#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int arr[maxn][maxn];
int main() {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> arr[i][j];
	int q;
	cin >> q;
	while(q--) {
		int u,d,l,r;
		cin >> u >> d >> l >> r;
		int ans = arr[u][l];
		for(int i=u;i<=d;i++)
			for(int j=l;j<=r;j++)
				ans = max(ans, arr[i][j]);
		cout << ans << endl;
	}
	return 0;
}
