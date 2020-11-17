// WA, greedy by Yazmau
#include<stdio.h>
#define maxn 25
int weight[maxn],value[maxn];
double cp[maxn];
long long greedy_by_cp_value(int n,int m,int a,int b) {
	if(weight[a] + weight[b] > m)	return 0;

	for(int i=1;i<=n;i++)
		cp[i] = (double)value[i] / weight[i];
	m = m - weight[a] - weight[b];
	long long ret = value[a] + value[b];
	cp[a] = cp[b] = -1.0;

	while(1) {
		int idx = 0;
		for(int i=1;i<=n;i++)
			if(cp[i] > cp[idx])
				idx = i;
		if(idx == 0)	break;
		if(weight[idx] <= m) {
			m -= weight[idx];
			ret += value[idx];
		}
		cp[idx] = -1.0;
	}

	return ret;
}
int vis[maxn];
long long greedy_by_value(int n,int m,int a,int b) {
	if(weight[a] + weight[b] > m)	return 0;

	for(int i=1;i<=n;i++)	vis[i] = 0;
	m = m - weight[a] - weight[b];
	long long ret = value[a] + value[b];
	vis[a] = vis[b] = 1;

	while(1) {
		int idx = 0;
		for(int i=1;i<=n;i++)
			if(!vis[i] && (value[i] > value[idx] || (value[i] == value[idx] && weight[i] < weight[idx])))
				idx = i;
		if(idx == 0)	break;
		if(weight[idx] <= m) {
			m -= weight[idx];
			ret += value[idx];
		}
		vis[idx] = 1;
	}
	return ret;
}
long long greedy_by_weight(int n,int m,int a,int b) {
	if(weight[a] + weight[b] > m)	return 0;

	for(int i=1;i<=n;i++)	vis[i] = 0;
	m = m - weight[a] - weight[b];
	long long ret = value[a] + value[b];
	vis[a] = vis[b] = 1;
	
	weight[0] = 1000000000;
	while(1) {
		int idx = 0;
		for(int i=1;i<=n;i++)
			if(!vis[i] && (weight[i] < weight[idx] || (weight[i] == weight[idx] && value[i] > value[idx])))
				idx = i;
		if(idx == 0)	break;
		if(weight[idx] <= m) {
			m -= weight[idx];
			ret += value[idx];
		}
		vis[idx] = 1;
	}
	return ret;
}
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&weight[i],&value[i]);
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		long long ans = greedy_by_cp_value(n,m,a,b);
		long long now = greedy_by_value(n,m,a,b);
		if(now > ans)	ans = now;
		now = greedy_by_weight(n,m,a,b);
		if(now > ans)	ans = now;
		printf("%lld\n",ans);
	}
	return 0;
}
