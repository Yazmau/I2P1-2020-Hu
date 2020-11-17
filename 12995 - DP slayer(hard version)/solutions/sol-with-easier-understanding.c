// solution by Yazmau
#include<stdio.h>
#define maxn 25
int weight[maxn],value[maxn];
int skip[maxn];
long long sol(int dep,int n,int m,long long w,long long v) {
	if(w > m)	return 0;
	if(skip[dep] == 1)	return sol(dep + 1,n,m,w,v);
	if(dep == n)
		return v;
	else {
		long long ret = sol(dep + 1,n,m,w,v);

		long long temp = sol(dep + 1,n,m,w + weight[dep],v + value[dep]);
		if(temp > ret)	ret = temp;
		
		return ret;
	}
}
long long ans[maxn][maxn];
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
		printf("%lld\n",ans[a - 1][b - 1]);
	}
	return 0;
}
