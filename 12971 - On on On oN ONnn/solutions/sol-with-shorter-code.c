// solution with shorter code by Yazmau
#include<stdio.h>
#define maxn 25
int state[maxn][maxn];
int ans = -1;
void sol(int i,int j,int n,int m,int sum) {
	if(i == n + 1) {
		for(int x=1;x<=n;x++)
			for(int y=1;y<=m;y++)
				if(state[x][y] == 0)
					return;
		if(ans == -1 || sum < ans)
			ans = sum;
	}
	else {
		int nxt_i = i, nxt_j = j + 1;
		if(nxt_j == m + 1)	nxt_i++, nxt_j = 1;
		
		sol(nxt_i,nxt_j,n,m,sum);
		
		state[i][j] ^= 1; state[i - 1][j] ^= 1; state[i][j - 1] ^= 1; state[i][j + 1] ^= 1; state[i + 1][j] ^= 1;
		sol(nxt_i,nxt_j,n,m,sum + 1);
		state[i][j] ^= 1; state[i - 1][j] ^= 1; state[i][j - 1] ^= 1; state[i][j + 1] ^= 1; state[i + 1][j] ^= 1;
	}
}
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&state[i][j]);

	sol(1,1,n,m,0);
	if(ans == -1)
		printf("no solution\n");
	else
		printf("%d\n",ans);
	return 0;
}
