// solution by binary search by Yazmau
#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
		cin >> arr[i];
	sort(arr+1,arr+1+N);
	int Q;
	cin >> Q;
	while(Q--) {
		int x;
		cin >> x;
		cout << upper_bound(arr+1,arr+1+N,x) - arr - 1 << '\n';	
	}
	return 0;
}
