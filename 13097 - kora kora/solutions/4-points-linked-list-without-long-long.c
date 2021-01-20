// WA and TLE, 4 points, linked-list with sorting without long long by Yazmau
#include<stdio.h>
#include<stdlib.h>
#define maxn 100005
int arr[maxn];
int cmp(const void *a, const void *b) {
	if(*(int*)a < *(int*)b)	return -1;
	if(*(int*)a > *(int*)b)	return 1;
	return 0;
}
typedef struct node {
	struct node *prev, *next;
	int val;
} Node;
Node* createNode(int val) {
	Node* ret = (Node*)malloc(sizeof(Node));
	ret->prev = ret->next = NULL;
	ret->val = val;
	return ret;
}
int main() {
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	qsort(arr+1,N,sizeof(int),cmp);

	Node *head = createNode(arr[-1]), *temp = head, *mid;
	for(int i=1;i<=N;i++) {
		temp->next = createNode(arr[i]);
		temp->next->prev = temp;
		temp = temp->next;
		if(i == (N + 1) / 2)	mid = temp;
	}

	int Q;
	scanf("%d",&Q);
	for(int i=0,type;i<Q;i++) {
		scanf("%d",&type);
		if(type == 1) {
			mid = mid->prev;
			mid->next = mid->next->next;
			mid->next->prev = mid;
			N--;
			if(N % 2 == 1)	mid = mid->next;
		}
		else {
			int k;
			scanf("%d",&k);
			temp = head->next;
			for(int j=1;j<=N;j++) {
				if(j == k)	printf("%d\n",temp->val);
				temp->val /= 2ll;
				temp = temp->next;
			}
		}
	}
	return 0;
}
