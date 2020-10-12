// solution with easier strategy by Yazmau 
#include<stdio.h>
#define maxn 505
int main() {
	int n;
	scanf("%d",&n);

	int ans[maxn][maxn], cnt = 1;
	for(int i=1;i<=n;i++) {
		int len = (n - i + 1) * 2 - 1;
		/* go right */
		for(int j=0;j<len;j++)	ans[i][i + j] = cnt, cnt++;
		/* go down */
		for(int j=0;j<len;j++)	ans[i + j][i + len] = cnt, cnt++;
		/* go left */
		for(int j=0;j<len;j++)	ans[i + len][i + len - j] = cnt, cnt++;
		/* go up */
		for(int j=0;j<len;j++)	ans[i + len - j][i] = cnt, cnt++;
	}

	for(int i=1;i<=2*n;i++) {
		for(int j=1;j<=2*n;j++) {
			if(j != 1)	printf(" ");
			printf("%d",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
