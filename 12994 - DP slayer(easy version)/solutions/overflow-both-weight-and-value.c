// WA, overflow both weight and value by Yazmau
#include<stdio.h>
#define maxn 25
int weight[maxn],value[maxn];
int sol(int dep,int n,int m,int w,int v) {
	if(w > m)	return 0;
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
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d %d",&weight[i],&value[i]);
	printf("%d\n",sol(0,n,m,0,0));
	return 0;
}
