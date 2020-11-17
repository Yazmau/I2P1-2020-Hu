// WA or MLE or RE, dp by Yazmau
#include<bits/stdc++.h>
#define maxv 1000005
using namespace std;
long long dp[maxv];
int main() {
	int n,m;
	cin >> n >> m;

	memset(dp,-1,sizeof dp);
	dp[0] = 0;
	for(int i=1,weight,value;i<=n;i++) {
		cin >> weight >> value;
		for(int j=m;j>=weight;j--)
			if(dp[j - weight] != -1) {
				long long new_val = dp[j - weight] + value;
				if(dp[j] == -1 || new_val > dp[j])
					dp[j] = new_val;
			}
	}
	cout << *max_element(dp,dp+1+m) << endl;
	return 0;
}
