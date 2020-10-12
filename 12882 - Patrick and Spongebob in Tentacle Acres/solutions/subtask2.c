// subtask 2 by Yazmau
#include<stdio.h>
#define maxn 105
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[maxn];
	for(int i=1;i<=m;i++)
		scanf("%d",&arr[i]);
	int q;
	scanf("%d",&q);
	while(q--) {
		int u,d,l,r;
		scanf("%d %d %d %d",&u,&d,&l,&r);
		int ans = arr[l];
		for(int i=l;i<=r;i++)
			if(arr[i] > ans)
				ans = arr[i];
		printf("%d\n",ans);
	}
	return 0;
}
