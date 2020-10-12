// subtask 2 by Yazmau
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
		int cnt = 1;
		for(int i=1;i<=m;i+=2) {
			if(i != 1)	printf(" ");
			printf("%d %d",cnt,cnt+3);
			cnt += 4;
		}
		printf("\n");

		cnt = 2;
		for(int i=1;i<=m;i+=2) {
			if(i != 1)	printf(" ");
			printf("%d %d",cnt,cnt+1);
			cnt += 4;
		}
		printf("\n");
	}
	return 0;
}

