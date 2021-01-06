// TLE, O(N^2+Q) by Yazmau
#include<stdio.h>
#define maxn 100005
int arr[maxn];
int main() {
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&arr[i]);

	for(int i=1;i<=N;i++)
		for(int j=2;j<=N;j++)
			if(arr[j - 1] > arr[j]) {
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}

	int Q;
	scanf("%d",&Q);
	int now = N;
	for(int i=0;i<Q;i++) {
		int x;
		scanf("%d",&x);
		while(now >= 1 && arr[now] > x)	now--;
		printf("%d\n",now);
	}
	return 0;
}
