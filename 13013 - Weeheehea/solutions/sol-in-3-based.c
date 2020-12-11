// solution in 3 based by Yazmau
#include<stdio.h>
int exist[60000];
int main() {
	int n;
	scanf("%d",&n);
	char s[15];
	for(int i=0;i<n;i++) {
		scanf("%s",s);
		int mask = 0;
		for(int j=0;j<10;j++) {
			int now = (s[j] == 'x' ? 2 : s[j] - '0');
			mask = mask * 3 + now;
		}
		exist[mask] = 1;
	}
	int ans = 0;
	for(int i=0;i<60000;i++)
		ans += exist[i];
	printf("%d\n",ans);
	return 0;
}
