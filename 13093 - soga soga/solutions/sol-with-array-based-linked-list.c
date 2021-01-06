// solution with array-based linked-list by Yazmau
#include<stdio.h>
#define maxn 500005
int arr[maxn],nxt[maxn],pre[maxn];
int main() {
	int N;
	scanf("%d",&N);
	nxt[0] = 1;
	for(int i=1;i<=N;i++)
		scanf("%d", &arr[i]), nxt[i] = i + 1, pre[i] = i - 1;
	int Q;
	scanf("%d",&Q);
	int now = 1, mid = (N + 1) / 2;
	while(Q--) {
		int type;
		scanf("%d",&type);
		if(type == 1) {
			int dir;
			scanf("%d",&dir);
			now = (dir == -1 ? pre[now] : nxt[now]);
		}
		else if(type == 2) {
			printf("%d\n",arr[now]);
		}
		else {
			if(now == mid)	now = nxt[now];
			nxt[pre[mid]] = nxt[mid];
			pre[nxt[mid]] = pre[mid];
			mid = ((N & 1) ? pre[mid] : nxt[mid]);
			N--;
		}
	}
	return 0;
}
