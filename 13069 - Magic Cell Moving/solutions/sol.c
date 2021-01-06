// model solution by Yazmau
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node *next[4];
	int val;
} Node;
Node* newNode(int init) {
	Node* ret = (Node*)malloc(sizeof(Node));
	ret->next[0] = ret->next[1] = ret->next[2] = ret->next[3] = NULL;
	ret->val = init;
	return ret;
}
int main() {
	int Q;
	scanf("%d",&Q);
	
	Node *now = newNode(0), *portal = now;
	for(int i=0;i<Q;i++) {
		int type;
		scanf("%d",&type);
		if(type == 1) {
			int dir,val;
			scanf("%d %d",&dir,&val);
			now->next[dir] = newNode(val);
			now->next[dir]->next[(dir + 2) % 4] = now;
		}
		else if(type == 2) {
			int dir;
			scanf("%d",&dir);
			now = now->next[dir];
		}
		else if(type == 3) {
			int newVal;
			scanf("%d",&newVal);
			now->val = newVal;
		}
		else if(type == 4) {
			printf("%d\n",now->val);
		}
		else if(type == 5) {
			portal = now;
		}
		else if(type == 6) {
			now = portal;
		}
	}
	return 0;
}
