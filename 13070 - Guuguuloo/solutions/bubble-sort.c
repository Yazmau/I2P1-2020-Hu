// TLE, sort by bubble-sort by Yazmau
#include<stdio.h>
#include<stdlib.h>
#define maxn 100005
int arr[maxn];
typedef struct node {
	struct node *nxt, *pre;
	int val;
} Node;
Node* newNode(int val) {
	Node *ret = (Node*)malloc(sizeof(Node));
	ret->nxt = ret->pre = NULL;
	ret->val = val;
	return ret;
}
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

	Node *ptr = newNode(0), *nowX = ptr, *nowY = ptr;
	for(int i=1;i<=N;i++) {
		ptr->nxt = newNode(arr[i]);
		ptr->nxt->pre = ptr;
		ptr = ptr->nxt;
	}

	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++) {
		int type,val;
		scanf("%d %d",&type,&val);

		Node *now = (type == 1 ? nowX : nowY);
		while(now != NULL && now->val < val)	now = now->nxt;

		if(type == 1) {
			if(now != NULL && now->val == val) {
				Node *pre = now->pre, *nxt = now->nxt;
				pre->nxt = nxt;
				if(nxt != NULL)	nxt->pre = pre;
				if(nowY == now)	nowY = nowY->nxt;
				free(now);
				now = nxt;
			}
			nowX = now;
		}
		else {
			if(now != NULL && now->val == val)
				printf("Yes\n");
			else
				printf("No\n");
			nowY = now;
		}
	}
	return 0;
}
