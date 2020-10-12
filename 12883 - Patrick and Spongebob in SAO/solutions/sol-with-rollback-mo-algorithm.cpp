// solution with rollback Mo's algorithm by Yazmau
// its time complexity is O((n + q) * n^0.5)
#include<bits/stdc++.h>
#define pii pair<int,int>
#define maxn 505
using namespace std;
int arr[maxn];
int cnt[maxn],min_val[maxn],max_times;
stack<pii> recover;
void undo() {
	pii now = recover.top();
	recover.pop();
	int val = now.first, ori_val = now.second;
	if(ori_val != -1)
		min_val[cnt[val]] = ori_val;
	cnt[val]--;
	if(min_val[max_times] == 0)	max_times--;
}
void add(int val) {
	cnt[val]++;
	pii now = {val,-1};
	if(min_val[cnt[val]] == 0 || val < min_val[cnt[val]]) {
		now.second = min_val[cnt[val]];
		min_val[cnt[val]] = val;
	}
	recover.push(now);
	max_times = max(max_times, cnt[val]);
}
struct que{
	int l,r,tmp;
};
vector<que> ques[maxn];
int ans[maxn];
void Mo(int idx,int bound) {
	sort(ques[idx].begin(),ques[idx].end(),[=](que a,que b)->bool
		{return a.r < b.r;});
	int now_r = bound;
	for(que now : ques[idx]) {
		int l = now.l, r = now.r;
		if(r <= bound) {
			for(int i=l;i<=r;i++)
				add(arr[i]);
			ans[now.tmp] = min_val[max_times];
			while(!recover.empty())	undo();
		}
		else {
			while(now_r < r)	add(arr[++now_r]);
			for(int i=l;i<=bound;i++)	add(arr[i]);
			ans[now.tmp] = min_val[max_times];
			for(int i=l;i<=bound;i++)	undo();
		}
	}
	while(!recover.empty())	undo();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	int q, box = sqrt(n);
	cin >> q;
	for(int i=1,l,r;i<=q;i++) {
		cin >> l >> r;
		ques[l / box].push_back(que{l,r,i});
	}

	for(int i=0;i<505;i++)
		if(!ques[i].empty())
			Mo(i,min((i + 1) * box - 1,n));

	for(int i=1;i<=q;i++)
		cout << ans[i] << '\n';
	return 0;
}
