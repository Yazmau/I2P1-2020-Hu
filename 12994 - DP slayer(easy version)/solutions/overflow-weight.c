// WA, overflow weight by Yazmau
#include<stdio.h>
#define maxn 25
int weight[maxn],value[maxn];
long long sol(int dep,int n,int m,int w,long long v) {
	if(dep == n)
		return w <= m ? v : 0;
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
	printf("%lld\n",sol(0,n,m,0,0));
	return 0;
}