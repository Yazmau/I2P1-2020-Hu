// WA, greedy with cp-value by Yazmau
#include<stdio.h>
#define maxn 25
int weight[maxn],value[maxn];
double cp[maxn];
int main() {
	int n,w;
	scanf("%d %d",&n,&w);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&weight[i],&value[i]), cp[i] = (double)value[i] / weight[i];
	long long ans = 0;
	while(1) {
		int idx = 0;
		for(int i=1;i<=n;i++)
			if(cp[i] > cp[idx])
				idx = i;
		if(idx == 0)	break;
		if(weight[idx] <= w) {
			w -= weight[idx];
			ans += value[idx];
		}
		cp[idx] = -1.0;
	}
	printf("%lld\n",ans);
	return 0;
}
