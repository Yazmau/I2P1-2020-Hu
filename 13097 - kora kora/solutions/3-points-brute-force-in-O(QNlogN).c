// TLE, 3 point, O(QNlogN), brute forces by Yazmau
#include<stdio.h>
#include<stdlib.h>
#define maxn 100005
long long arr[maxn];
int cmp(const void *a, const void *b) {
	if(*(long long*)a < *(long long*)b)	return -1;
	if(*(long long*)a > *(long long*)b)	return 1;
	return 0;
}
int main() {
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
	
	int Q;
	scanf("%d",&Q);
	while(Q--) {
		qsort(arr+1,N,sizeof(long long),cmp);
		int type;
		scanf("%d",&type);
		if(type == 1) {
			for(int i=(N + 1) / 2;i<N;i++)
				arr[i] = arr[i + 1];
			N--;
		}
		else {
			int k;
			scanf("%d",&k);
			printf("%lld\n",arr[k]);
			for(int i=1;i<=N;i++)	arr[i] >>= 1;
		}
	}
	return 0;
}
