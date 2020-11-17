// WA, overflow by Yazmau
#include<stdio.h>
#define maxn 25
int weight[maxn],value[maxn];
int skip[maxn];
int sol(int dep,int n,int m,int w,int v) {
	if(w > m)	return 0;
	if(skip[dep] == 1)	return sol(dep + 1,n,m,w,v);
	if(dep == n)
		return v;
	else {
		int ret = 0;
		for(int i=0;i<2;i++) {
			int now = sol(dep + 1,n,m,w,v);
			if(now > ret)	ret = now;
			w += weight[dep], v += value[dep];
		}
		return ret;
	}
}
int ans[maxn][maxn];
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d %d",&weight[i],&value[i]);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++) {
			skip[i] = skip[j] = 1;
			ans[i][j] = sol(0,n,m,weight[i] + weight[j],value[i] + value[j]);
			skip[i] = skip[j] = 0;
		}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",ans[a - 1][b - 1]);
	}
	return 0;
}
