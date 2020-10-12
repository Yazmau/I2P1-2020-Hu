// model solution by Yazmau
#include<stdio.h>
#define maxn 505
int main() {
	int n,m;
	scanf("%d %d",&n,&m);

	int ans[maxn][maxn], cnt = 1;
	for(int j=1;j<=m;j+=2) {
		for(int i=1;i<=n;i++)	ans[i][j] = cnt++;
		for(int i=n;i>=1;i--)	ans[i][j + 1] = cnt++;
	}

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(j != 1)	printf(" ");
			printf("%d",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
