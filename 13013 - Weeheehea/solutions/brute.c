// TLE, brute force by Yazmau
#include<stdio.h>
#include<string.h>
#define maxn 100005
char s[maxn][15];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]);
	int ans = 0;
	for(int i=1;i<=n;i++) {
		int same = 0;
		for(int j=1;j<i;j++)
			if(strcmp(s[i],s[j]) == 0) {
				same = 1;
				break;
			}
		if(same == 0)	ans++;
	}
	printf("%d\n",ans);
	return 0;
}
