// solution with memoization by Yazmau
#include<stdio.h>
#define maxn 100005
char A[maxn][3][5],B[3][5];
void swap(char *a,char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
int encoding(char board[][5]) {
	int ret = 0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			ret = ret * 3 + (board[i][j] == 'x' ? 2 : board[i][j] - '0');
	return ret;
}
int suc[20000][15];
int sol(int dep,int K,char board[][5],int x,int y) {
	int enc = encoding(board);
	if(suc[enc][dep] != 0)	return suc[enc][dep];
	int same = 1;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(board[i][j] != B[i][j])
				same = 0;
	if(same == 1)	return suc[enc][dep] = 1;
	if(dep == K)	return suc[enc][dep] = -1;
	static int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
	int ret = -1;
	for(int dir=0;dir<4;dir++) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3)	continue;
		swap(&board[x][y],&board[nx][ny]);
		if(sol(dep + 1,K,board,nx,ny) == 1)	ret = 1;
		swap(&board[x][y],&board[nx][ny]);
	}
	return suc[enc][dep] = ret;
}
int main() {
	int N,K;
	scanf("%d %d",&N,&K);
	for(int i=1;i<=N;i++)
		for(int j=0;j<3;j++)
			scanf("%s",A[i][j]);
	for(int i=0;i<3;i++)
		scanf("%s",B[i]);
	int ans = 0;
	for(int i=1;i<=N;i++) {
		int x,y;
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				if(A[i][j][k] == 'x')
					x = j, y = k;
		if(sol(0,K,A[i],x,y) == 1)	ans++;
	}
	printf("%d\n",ans);
	return 0;
}
