// TLE, 6 points, linked-list with sorting with pruning of k by Yazmau
#include<stdio.h>
#include<stdlib.h>
#define maxn 100005
long long arr[maxn];
int cmp(const void *a, const void *b) {
	if(*(long long*)a < *(long long*)b)	return -1;
	if(*(long long*)a > *(long long*)b)	return 1;
	return 0;
}
typedef struct node {
	struct node *prev, *next;
	long long val;
} Node;
Node* createNode(long long val) {
	Node* ret = (Node*)malloc(sizeof(Node));
	ret->prev = ret->next = NULL;
	ret->val = val;
	return ret;
}
int main() {
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%lld",&arr[i]);
	qsort(arr+1,N,sizeof(long long),cmp);
	long long maxOp2Time = arr[N];
	
	Node *head = createNode(arr[-1]), *temp = head, *mid;
	for(int i=1;i<=N;i++) {
		temp->next = createNode(arr[i]);
		temp->next->prev = temp;
		temp = temp->next;
		if(i == (N + 1) / 2)	mid = temp;
	}

	int Q;
	scanf("%d",&Q);
	long long op2Cnt = 0;
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
			long long ans = 0;
			if(op2Cnt < maxOp2Time) {
				temp = head->next;
				for(int j=1;j<=N;j++) {
					if(j == k)	ans = temp->val;
					temp->val /= 2ll;
					temp = temp->next;
				}
			}
			printf("%lld\n",ans);
			op2Cnt++;
		}
	}
	return 0;
}
