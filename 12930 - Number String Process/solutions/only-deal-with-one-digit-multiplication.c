// WA
#include<stdio.h>
#define maxn 1005
int main() {
	int n;
	char s[maxn];
	scanf("%d %s",&n,s);
	int q;
	scanf("%d",&q);
	while(q--) {
		int a,b,sz;
		scanf("%d %d %d",&a,&b,&sz);
		printf("%d\n",(s[a] - '0') * (s[b] - '0'));
	}
	return 0;
}
