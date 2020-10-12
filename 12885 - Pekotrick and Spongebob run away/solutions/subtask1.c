// subtask 1 by Yazmau
#include<stdio.h>
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++) {
		if(i != 1)	printf(" ");
		printf("%d",i);
	}
	printf("\n");
	return 0;
}

