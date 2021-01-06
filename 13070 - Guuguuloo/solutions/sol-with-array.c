// solution in array-implementation by Yazmau
#include<stdio.h>
#include<stdlib.h>
#define maxn 100005
int arr[maxn];
int cmp(const void* a, const void* b) {
	if(*(int*)a < *(int*)b)	return -1;
	if(*(int*)a > *(int*)b)	return 1;
	return 0;
}
int skip[maxn];
int main() {
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	
	qsort(arr+1,N,sizeof(int),cmp);
	
	int Q;
	scanf("%d",&Q);
	int nowX = 1, nowY = 1;
	while(Q--) {
		int type,val;
		scanf("%d %d",&type,&val);
		if(type == 1) {
			while(nowX <= N && arr[nowX] < val)	nowX++;
			if(nowX <= N && arr[nowX] == val)	skip[nowX] = 1, nowX++;
		}
		else {
			while(nowY <= N && arr[nowY] < val) nowY++;
			if(nowY <= N && skip[nowY] == 0 && arr[nowY] == val)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
}
