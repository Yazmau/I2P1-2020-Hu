// model solution by Yazmau
#include<stdio.h>
#define maxn 505
int main() {
	int n;
	scanf("%d",&n);

	int delta_i[] = {0,1,0,-1}, delta_j[] = {1,0,-1,0};
	int ans[maxn][maxn];
	int pos_i = 1, pos_j = 1, cnt = 1;
	for(int len=2*n-1;len>=1;len-=2) {
		for(int type=0;type<4;type++)
			for(int step=0;step<len;step++) {
				ans[pos_i][pos_j] = cnt;
				pos_i += delta_i[type], pos_j += delta_j[type];
				cnt++;
			}
		pos_i++, pos_j++;
	}

	for(int i=1;i<=2*n;i++) {
		for(int j=1;j<=2*n;j++) {
			if(j != 1)	printf(" ");
			printf("%d",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
