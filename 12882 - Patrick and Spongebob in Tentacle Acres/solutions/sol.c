// model solution by Yazmau
#include<stdio.h>
#define maxn 105
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[maxn][maxn];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&arr[i][j]);
	int q;
	scanf("%d",&q);
	while(q--) {
		int u,d,l,r;
		scanf("%d %d %d %d",&u,&d,&l,&r);
		int ans = arr[u][l];
		for(int i=u;i<=d;i++)
			for(int j=l;j<=r;j++)
				if(arr[i][j] > ans)
					ans = arr[i][j];
		printf("%d\n",ans);
	}
	return 0;
}
