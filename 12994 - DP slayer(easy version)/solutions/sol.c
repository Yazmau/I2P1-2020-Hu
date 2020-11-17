// solution by Yazmau
#include<stdio.h>
#define maxn 25
int weight[maxn],value[maxn];
long long sol(int dep,int n,int m,long long w,long long v) {
	if(w > m)	return 0;
	if(dep == n)
		return v;
	else {
		long long ret = 0;
		for(int i=0;i<2;i++) {
			long long now = sol(dep + 1,n,m,w,v);
			if(now > ret)	ret = now;
			w += weight[dep], v += value[dep];
		}
		return ret;
	}
}
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d %d",&weight[i],&value[i]);
	/*
		int q,a,b;
		scanf("%d %d %d",&q,&a,&b);
	*/
	printf("%lld\n",sol(0,n,m,0,0));
	return 0;
}
