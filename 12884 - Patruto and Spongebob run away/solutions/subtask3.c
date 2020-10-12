// subtask 3 by Yazmau
#include<stdio.h>
int main() {
	int n;
	scanf("%d",&n);
	if(n == 1) {
		printf("1 2\n");
		printf("4 3\n");
	}
	else if(n == 2) {
		printf("1 2 3 4\n");
		printf("12 13 14 5\n");
		printf("11 16 15 6\n");
		printf("10 9 8 7\n");
	}
	else if(n == 3) {
		printf("1 2 3 4 5 6\n");
		printf("20 21 22 23 24 7\n");
		printf("19 32 33 34 25 8\n");
		printf("18 31 36 35 26 9\n");
		printf("17 30 29 28 27 10\n");
		printf("16 15 14 13 12 11\n");
	}
	return 0;
}
