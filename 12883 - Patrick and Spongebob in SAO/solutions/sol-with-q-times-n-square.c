// solution whose time time complexity is O(qn^2) by Yazmau
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
		int ans = arr[l] , cnt = 1;
		for(int i=l;i<=r;i++) {
			int now = 0;
			for(int j=i;j<=r;j++)
				if(arr[j] == arr[i])
					now++;
			if(now > cnt || (now == cnt && arr[i] < ans))
				ans = arr[i], cnt = now;
		}
		printf("%d\n",ans);
	}
	return 0;
}
