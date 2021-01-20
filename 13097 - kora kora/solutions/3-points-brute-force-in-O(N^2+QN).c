// TLE, 3 point, O(N^2+QN), brute forces by Yazmau
#include<stdio.h>
#define maxn 100005
long long arr[maxn];
int main() {
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
	
	for(int i=1;i<=N;i++)
		for(int j=1;j<N;j++)
			if(arr[j] > arr[j + 1]) {
				long long temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	
	int Q;
	scanf("%d",&Q);
	while(Q--) {
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
