// TLE by Yazmau
#include<stdio.h>
#define maxn 100005
int arr[maxn];
int main() {
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	int Q;
	scanf("%d",&Q);
	while(Q--) {
		int x;
		scanf("%d",&x);
		int ans = 0;
		for(int i=1;i<=N;i++)
			if(arr[i] <= x)
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}
