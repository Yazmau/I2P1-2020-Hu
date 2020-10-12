// solution with the strategy problem mentioned by Yazmau
#include<stdio.h>
#define maxn 505
int main() {
	int n;
	scanf("%d",&n);

	int ans[maxn][maxn] = {};
	ans[1][1] = 1;
	int pos_i = 1, pos_j = 1, cnt = 2;
	while(cnt <= 4 * n * n) {
		while(pos_j + 1 <= 2 * n && ans[pos_i][pos_j + 1] == 0) {
			pos_j++;
			ans[pos_i][pos_j] = cnt;
			cnt++;
		}
		while(pos_i + 1 <= 2 * n && ans[pos_i + 1][pos_j] == 0) {
			pos_i++;
			ans[pos_i][pos_j] = cnt;
			cnt++;
		}
		while(pos_j - 1 >= 1 && ans[pos_i][pos_j - 1] == 0) {
			pos_j--;
			ans[pos_i][pos_j] = cnt;
			cnt++;
		}
		while(pos_i - 1 >= 1 && ans[pos_i - 1][pos_j] == 0) {
			pos_i--;
			ans[pos_i][pos_j] = cnt;
			cnt++;
		}
	}

	for(int i=1;i<=2 * n;i++) {
		for(int j=1;j<=2 * n;j++) {
			if(j != 1)	printf(" ");
			printf("%d",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
