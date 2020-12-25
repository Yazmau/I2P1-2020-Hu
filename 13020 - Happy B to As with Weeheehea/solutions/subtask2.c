// subtask 2 by Yazmau
#include<stdio.h>
#define maxn 100005
char A[maxn][3][5],B[3][5];
void swap(char *a,char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
int sol(int dep,int K,char board[][5],int x,int y) {
	int same = 1;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(board[i][j] != B[i][j])
				same = 0;
	if(same == 1)	return 1;
	if(dep == K)	return 0;
	static int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
	for(int dir=0;dir<4;dir++) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3)	continue;
		swap(&board[x][y],&board[nx][ny]);
		if(sol(dep + 1,K,board,nx,ny) == 1)	return 1;
		swap(&board[x][y],&board[nx][ny]);
	}
	return 0;
}
int suc[20000];
int encoding(char board[][5]) {
	int ret = 0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			ret = ret * 3 + (board[i][j] == 'x' ? 2 : board[i][j] - '0');
	return ret;
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
		int enc = encoding(A[i]);
		if(suc[enc] == 0)	suc[enc] = (sol(0,K,A[i],x,y) == 1 ? 1 : -1);
		if(suc[enc] == 1)	ans++;
	}
	printf("%d\n",ans);
	return 0;
}
