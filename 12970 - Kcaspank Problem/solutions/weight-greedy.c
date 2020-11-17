// WA, greedy with weight by Yazmau
#include<stdio.h>
#define maxn 25
int weight[maxn],value[maxn];
int main() {
	int n,w;
	scanf("%d %d",&n,&w);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&weight[i],&value[i]);
	long long ans = 0;
	weight[0] = 1000;
	while(1) {
		int idx = 0;
		for(int i=1;i<=n;i++)
			if(weight[i] < weight[idx] || (weight[i] == weight[idx] && value[i] > value[idx]))
				idx = i;
		if(idx == 0)	break;
		if(weight[idx] <= w) {
			w -= weight[idx];
			ans += value[idx];
		}
		weight[idx] = 1005;
	}
	printf("%lld\n",ans);
	return 0;
}
