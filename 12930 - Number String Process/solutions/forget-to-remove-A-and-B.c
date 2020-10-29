// WA, forget to remove A and B for each query
#include<stdio.h>
#define maxn 1005
int get(char* s,int l,int r) {
	int ret = 0;
	for(int i=l;i<=r;i++)
		ret = ret * 10 + s[i] - '0';
	return ret;
}
int main() {
	int n;
	char s[maxn];
	scanf("%d %s",&n,s);
	int q;
	scanf("%d",&q);
	while(q--) {
		int a,b,sz;
		scanf("%d %d %d",&a,&b,&sz);
		int A = get(s,a,a + sz - 1), B = get(s,b,b + sz - 1);
		printf("%lld\n",(long long)A * B);
	}
	return 0;
}
