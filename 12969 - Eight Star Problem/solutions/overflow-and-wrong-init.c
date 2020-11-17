// WA, overflow and wrong initial value by Yazmau
#include<stdio.h>
#define maxn 15
int arr[maxn][maxn];
int col[maxn],mdig[maxn<<1],adig[maxn<<1];
int sol(int i,int n,int sum) {
	if(i == n)
		return sum;
	else {
		int ret = 0;
		for(int j=0;j<n;j++)
			if(!col[j] && !mdig[i + j] && !adig[i - j + maxn]) {
				col[j] = mdig[i + j] = adig[i - j + maxn] = 1;
				int now = sol(i + 1,n,sum + arr[i][j]);
				if(now > ret)	ret = now;
				col[j] = mdig[i + j] = adig[i - j + maxn] = 0;
			}
		return ret;
	}
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	int ans = sol(0,n,0);
	if(ans == 0)
		printf("no solution\n");
	else
		printf("%d\n",ans);
	return 0;
}
