// subtask 4 by Yazmau
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
	else if(n == 4) {
		printf("1 2 3 4 5 6 7 8\n");
		printf("28 29 30 31 32 33 34 9\n");
		printf("27 48 49 50 51 52 35 10\n");
		printf("26 47 60 61 62 53 36 11\n");
		printf("25 46 59 64 63 54 37 12\n");
		printf("24 45 58 57 56 55 38 13\n");
		printf("23 44 43 42 41 40 39 14\n");
		printf("22 21 20 19 18 17 16 15\n");
	}
	return 0;
}
