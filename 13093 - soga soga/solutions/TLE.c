// TLE with brute-forces by Yazmau
#include<stdio.h>
#define maxn 500005
int arr[maxn];
int main() {
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	int Q;
	scanf("%d",&Q);
	int now = 1;
	while(Q--) {
		int type;
		scanf("%d",&type);
		if(type == 1) {
			int dir;
			scanf("%d",&dir);
			now += dir;
		}
		else if(type == 2) {
			printf("%d\n",arr[now]);
		}
		else {
			if(now > (N + 1) / 2)	now--;
			for(int i=(N+1)/2;i<N;i++)
				arr[i] = arr[i + 1];
			N--;
		}
	}
	return 0;
}
