// wrong bitmask by Yazmau
#include<stdio.h>
int exist[123456];
int main() {
	int n;
	scanf("%d",&n);
	char s[15];
	int ans = 0;
	for(int i=0;i<n;i++) {
		scanf("%s",s);
		int bitmask = 0;
		for(int j=0;j<10;j++)
			bitmask = (bitmask << 1) | (s[j] - '0');
		ans += 1 - exist[bitmask];
		exist[bitmask] = 1;
		
	}
	printf("%d\n",ans);
	return 0;
}
