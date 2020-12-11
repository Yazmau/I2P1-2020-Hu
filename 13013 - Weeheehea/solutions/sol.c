// model solution by Yazmau
#include<stdio.h>
#define maxn 520
int tran(char *s,int xPos) {
	int ret = 0;
	for(int i=0;i<10;i++) {
		if(i == xPos)	continue;
		ret = (ret << 1) | (s[i] - '0');
	}
	return ret;
}
int exist[10][maxn];
int main() {
	int n;
	scanf("%d",&n);
	char s[15];
	for(int i=0;i<n;i++) {
		scanf("%s",s);
		int xPos = -1;
		for(int j=0;j<10;j++)
			if(s[j] == 'x')
				xPos = j;
		exist[xPos][tran(s,xPos)] = 1;
	}
	int ans = 0;
	for(int i=0;i<10;i++)
		for(int j=0;j<maxn;j++)
			ans += exist[i][j];
	printf("%d\n",ans);
	return 0;
}
