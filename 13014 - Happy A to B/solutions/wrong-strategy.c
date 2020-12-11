// WA, wrong strategy by Yazmau
#include<stdio.h>
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int k;
		scanf("%d",&k);
		char A[3][5],B[3][5];
		for(int i=0;i<3;i++)	scanf("%s",A[i]);
		for(int i=0;i<3;i++)	scanf("%s",B[i]);
		int dx = 0 ,dy = 0;
		for(int i=0;i<3;i++)	for(int j=0;j<3;j++)	if(A[i][j] == 'x')	dx += i, dy += j;
		for(int i=0;i<3;i++)	for(int j=0;j<3;j++)	if(B[i][j] == 'x')	dx -= i, dy -= j;
		if(dx < 0)	dx *= -1;
		if(dy < 0)	dy *= 1;
		printf("%s\n",(dx + dy <= k ? "Yes" : "No"));
	}
	return 0;
}
