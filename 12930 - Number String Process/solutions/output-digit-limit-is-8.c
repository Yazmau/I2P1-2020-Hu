// WA, the limit of digit of output is 8
#include<stdio.h>
#define maxn 1005
#define digit 8
void output(char* s,int l1,int r1,int l2,int r2) {
	int ans[digit] = {};
	for(int i=r1;i>=l1;i--)
		for(int j=r2;j>=l2;j--)
			ans[r1 - i + r2 - j] += (s[i] - '0') * (s[j] - '0');
	for(int i=0;i<digit;i++)
		if(ans[i] >= 10) {
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
	int st = digit - 1;
	while(ans[st] == 0)	st--;
	while(st >= 0)	printf("%d",ans[st--]);
	printf("\n");

	for(int i=l1;i<=r1;i++)	s[i] = '@';
	for(int i=l2;i<=r2;i++)	s[i] = '@';
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
		output(s,a,a + sz - 1,b,b + sz - 1);
		
		int idx = 0;
		for(int i=0;i<n;i++)
			if(s[i] != '@')
				s[idx++] = s[i];
		n = idx;
	}
	return 0;
}
