// solution by Yazmau
#include<stdio.h>
#define maxn 25
int arr[maxn][maxn],rev[maxn][maxn];
int ans = -1;
void sol(int i,int j,int n,int m,int sum) {
	if(i == n) {
		int delta_x[] = {-1,0,0,1}, delta_y[] = {0,-1,1,0};
		for(int x=0;x<n;x++)
			for(int y=0;y<m;y++) {
				int now = arr[x][y] ^ rev[x][y];
				for(int type=0;type<4;type++) {
					int nx = x + delta_x[type], ny = y + delta_y[type];
					if(nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;
					now ^= rev[nx][ny];
				}
				if(now == 0)	return;
			}
		if(ans == -1 || sum < ans)
			ans = sum;
	}
	else {
		int nxt_i = i, nxt_j = j + 1;
		if(nxt_j == m)	nxt_i++, nxt_j = 0;
		
		sol(nxt_i,nxt_j,n,m,sum);
		
		rev[i][j] = 1;
		sol(nxt_i,nxt_j,n,m,sum + 1);
		rev[i][j] = 0;
	}
}
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&arr[i][j]);

	sol(0,0,n,m,0);
	if(ans == -1)
		printf("no solution\n");
	else
		printf("%d\n",ans);
	return 0;
}
