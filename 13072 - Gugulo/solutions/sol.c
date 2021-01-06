// model solution by Yazmau
#include<stdio.h>
#include<stdlib.h>
#define maxn 100005
int arr[maxn];
int cmp(const void* a, const void* b) {
	if(*(int*)a < *(int*)b)	return -1;
	if(*(int*)a > *(int*)b)	return 1;
	return 0;
}
int main() {
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	
	qsort(arr+1,N,sizeof(int),cmp);

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
