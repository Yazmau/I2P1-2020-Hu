// acces wrong bound by Yazmau
#include<stdio.h>
#define maxn 15
void solve(int n,char (*s)[maxn]) {
	int delta_i[] = {1,0,1,1}, delta_j[] = {0,1,1,-1};
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(s[i][j] != '.') {
				for(int type=0;type<4;type++) {
					int cnt = 0;
					for(int k=0;k<5;k++) {
						int now_i = i + delta_i[type] * k, now_j = j + delta_j[type] * k;
						if(now_i < 0 || now_i > n || now_j < 0 || now_j > n)	break;
						if(s[i][j] == s[now_i][now_j])	cnt++;
					}
					if(cnt == 5) {
						if(s[i][j] == 'b')
							printf("black\n");
						else
							printf("white\n");
						return;
					}
				}
			}
	printf("none\n");
}
int main() {
	int q;
	scanf("%d",&q);
	while(q--) {
		char s[maxn][maxn];
		int n = 15;
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		solve(n,s);
	}
	return 0;
}
