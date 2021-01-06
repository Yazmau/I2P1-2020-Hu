// solution with array-based linked-list by Yazmau
#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int arr[maxn],nxt[maxn][4];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int Q;
	cin >> Q;
	int now = 0, portal = 0, cnt = 1;
	while(Q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int dir,val;
			cin >> dir >> val;

			arr[cnt] = val;
			nxt[now][dir] = cnt;
			nxt[cnt][(dir + 2) % 4] = now;
			cnt++;
		}
		else if(type == 2) {
			int dir;
			cin >> dir;
			now = nxt[now][dir];
		}
		else if(type == 3) {
			int new_val;
			cin >> new_val;
			arr[now] = new_val;
		}
		else if(type == 4) {
			cout << arr[now] << '\n';
		}
		else if(type == 5) {
			portal = now;
		}
		else {
			now = portal;
		}
	}
	return 0;
}
