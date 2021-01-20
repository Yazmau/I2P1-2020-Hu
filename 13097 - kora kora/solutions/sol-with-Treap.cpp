// solution with Treap by Yazmau
#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll arr[maxn];
mt19937 Rand(48763);
struct Treap {
	Treap *l,*r;
	int pri,size;
	ll val;
	Treap(ll _val) {
		l = r = nullptr;
		pri = Rand(), size = 1;
		val = _val;
	}
};
int SZ(Treap *p) {
	return p == nullptr ? 0 : p->size;
}
void pull(Treap *p) {
	p->size = 1 + SZ(p->l) + SZ(p->r);
}
Treap* merge(Treap *a,Treap *b) {
	if(a == nullptr)	return b;
	if(b == nullptr)	return a;
	if(a->pri > b->pri) {
		a->r = merge(a->r,b);
		pull(a);
		return a;
	}
	else {
		b->l = merge(a,b->l);
		pull(b);
		return b;
	}
}
void split(Treap *p,Treap *&a,Treap *&b,int k) {
	if(p == nullptr) {
		a = b = nullptr;
		return;
	}
	if(SZ(p->l) + 1 < k) {
		a = p;
		split(p->r,a->r,b,k - SZ(p->l) - 1);
		pull(a);
	}
	else {
		b = p;
		split(p->l,a,b->l,k);
		pull(b);
	}
}
ll sol(Treap *p,int k) {
	if(p == nullptr)	return 0;
	ll ret = 0; 
	if(SZ(p->l) == k - 1)	ret = p->val;
	p->val >>= 1;
	ret = max({ret,sol(p->l,k),sol(p->r,k - SZ(p->l) - 1)});
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
		cin >> arr[i];
	
	sort(arr+1,arr+1+N);
	Treap *root = nullptr;
	for(int i=1;i<=N;i++)
		root = merge(root, new Treap(arr[i]));
	
	int Q;
	cin >> Q;
	int cnt = 0;
	while(Q--) {
		int type;
		cin >> type;
		if(type == 1) {
			Treap *l,*mid,*r;
			int k = (root->size + 1) / 2;
			split(root,mid,r,k);
			split(mid,l,mid,k - 1);
			root = merge(l,r);
		}
		else {
			int k;
			cin >> k;
			if(cnt >= 60)
				cout << 0 << '\n';
			else
				cout << sol(root,k) << '\n';
			cnt++;
		}
	}
	return 0;
}
