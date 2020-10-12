// new subtask 2 by Yazmau
#include<stdio.h>
#define maxn 505
int main() {
	int n;
	scanf("%d",&n);
	int arr[maxn];
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	int q;
	scanf("%d",&q);
	while(q--) {
		int l,r;
		scanf("%d %d",&l,&r);
		int cnt1 = 0, cnt2 = 0;
		for(int i=l;i<=r;i++)
			if(arr[i] == 1)
				cnt1++;
			else
				cnt2++;
		int ans = 1;
		if(cnt2 > cnt1)	ans = 2;
		printf("%d\n",ans);
	}
	return 0;
}
