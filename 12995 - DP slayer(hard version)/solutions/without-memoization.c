// TLE, without memoization by Yazmau
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
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d %d",&weight[i],&value[i]);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		skip[a - 1] = skip[b - 1] = 1;
		printf("%lld\n",sol(0,n,m,weight[a - 1] + weight[b - 1],value[a - 1] + value[b - 1]));
		skip[a - 1] = skip[b - 1] = 0;
	}
	return 0;
}
