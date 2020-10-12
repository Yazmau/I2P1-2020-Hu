// another implementation for subtask 2 by Yazmau
#include<stdio.h>
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	if(n == 1) {
		for(int i=1;i<=m;i++) {
			if(i != 1)	printf(" ");
			printf("%d",i);
		}
		printf("\n");
	}
	else if(n == 2) {
		int upper[505], lower[505], cnt = 1;
		for(int i=1;i<=m;i++) {
			if(i&1) {
				upper[i] = cnt++;
				lower[i] = cnt++;
			}
			else {
				lower[i] = cnt++;
				upper[i] = cnt++;
			}
		}
		for(int i=1;i<=m;i++) {
			if(i != 1)	printf(" ");
			printf("%d",upper[i]);
		}
		printf("\n");
		for(int i=1;i<=m;i++) {
			if(i != 1)	printf(" ");
			printf("%d",lower[i]);
		}
		printf("\n");
	}
	return 0;
}

