// WA, forget moving when removing(the 3rd type of operation) by Yazmau
#include<stdio.h>
#include<stdlib.h>
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
	
	Node *head = createNode(-1), *temp = head, *mid;
	for(int i=1,val;i<=N;i++) {
		scanf("%d",&val);
		temp->next = createNode(val);
		temp->next->prev = temp;
		temp = temp->next;
		if(i == (N + 1) / 2)	mid = temp;
	}
	temp = head->next;

	int Q;
	scanf("%d",&Q);
	for(int i=0,type;i<Q;i++) {
		scanf("%d",&type);
		if(type == 1) {
			int dir;
			scanf("%d",&dir);
			temp = (dir == -1 ? temp->prev : temp->next);
		}
		else if(type == 2) {
			printf("%d\n",temp->val);
		}
		else {
			mid = mid->prev;
			// if(temp == mid->next)	temp = mid->next->next;
			mid->next = mid->next->next;
			mid->next->prev = mid;
			N--;
			if(N % 2 == 1)	mid = mid->next;
		}
	}
	return 0;
}
