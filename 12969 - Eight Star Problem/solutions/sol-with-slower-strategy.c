// solution with slower strategy by Yazmau
#include<stdio.h>
#define maxn 15
#define INF 123456789123ll
int arr[maxn][maxn];
long long ans[maxn][maxn];
long long sol(int dep,int n) {
	if(dep == n + 1) {
		long long ret = 0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(ans[i][j] != -INF)
					ret += ans[i][j];
		return ret;
	}
	else {
		long long ret = -INF;
		for(int j=1;j<=n;j++) {
			int tag = 1, delta_j[] = {0,-1,1};
			for(int type=0;type<3;type++) {
				for(int step=1;step<dep;step++) {
					int now_i = dep + (-1) * step, now_j = j + delta_j[type] * step;
					if(1 <= now_j && now_j <= n && ans[now_i][now_j] != -INF)
						tag = 0;
				}
			}

			if(tag == 1) {
				ans[dep][j] = arr[dep][j];
				long long now = sol(dep + 1,n);
				if(now > ret)	ret = now;
				ans[dep][j] = -INF;
			}
		}
		return ret;
	}
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&arr[i][j]), ans[i][j] = -INF;
	long long now = sol(1,n);
	if(now == -INF)
		printf("no solution\n");
	else
		printf("%lld\n",now);
	return 0;
}
