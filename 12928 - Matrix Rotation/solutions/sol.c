// model solution by Yazmau
#include<stdio.h>
#define maxn 105
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int mat[maxn][maxn];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&mat[i][j]);
	int q;
	scanf("%d",&q);

	q %= 4;
	for(int t=0;t<q;t++) {
		int new_mat[maxn][maxn];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				new_mat[j][n - i - 1] = mat[i][j];
		// swap n,m
		int temp = n;	n = m;	m = temp;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				mat[i][j] = new_mat[i][j];
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(j != 0)	printf(" ");
			printf("%d",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
