// model solution by Yazmau
#include<stdio.h>
char A[3][5],B[3][5];
void swap(char *a,char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
int dfs(int dep,int k,int x,int y) {
	static int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
	int same = 1;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(A[i][j] != B[i][j])
				same = 0;
	if(same == 1)	return 1;
	if(dep == k)	return 0;
	for(int i=0;i<4;i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
			swap(&A[x][y],&A[nx][ny]);
			if(dfs(dep + 1,k,nx,ny) == 1)	return 1;
			swap(&A[x][y],&A[nx][ny]);
		}
	}
	return 0;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int k;
		scanf("%d",&k);
		for(int i=0;i<3;i++)	scanf("%s", A[i]);
		for(int i=0;i<3;i++)	scanf("%s", B[i]);
		int x = -1, y = -1;
		for(int i=0;i<3;i++)	for(int j=0;j<3;j++)	if(A[i][j] == 'x')	x = i, y = j;
		printf("%s\n",(dfs(0,k,x,y) == 1 ? "Yes" : "No"));
	}
	return 0;
}
