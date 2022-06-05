// 練習0,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

struct LazySegTree {
	int n;
	vector<ll> node, lazy;
	LazySegTree(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		node.resize(2*n-1);
		lazy.resize(2*n-1);
	}
	void eval(int k, int l, int r) {
		if (lazy[k] != 0) {
			node[k] += lazy[k];
			if (r-l > 1) {
				lazy[k*2+1] += lazy[k] / 2;
				lazy[k*2+2] += lazy[k] / 2;
			}
			lazy[k] = 0;
		}
	}
	void add(int a, int b, ll x, int k=0, int l=0, int r=0) {
		if (l==0 && r==0) r = n;
		eval(k, l, r);
		if (r<=a || b<=l) return;
		if (a<=l && r<=b) {
			lazy[k] += (r-l) * x;
			eval(k, l, r);
		}
		else {
			add(a, b, x, k*2+1, l, l+(r-l)/2);
			add(a, b, x, k*2+2, l+(r-l)/2, r);
			node[k] = node[k*2+1] + node[k*2+2];
		}
	}
	ll getSum(int a, int b, int k=0, int l=0, int r=0) {
		if (l==0 && r==0) r = n;
		eval(k, l, r);
		if (r<=a || b<=l) return 0;
		if (a<=l && r<=b) return node[k];
		else {
			ll vl = getSum(a, b, k*2+1, l, l+(r-l)/2);
			ll vr = getSum(a, b, k*2+2, l+(r-l)/2, r);
			return vl + vr;
		}
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	LazySegTree lst(n);
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 0) {
			int s, t, x;
			cin >> s >> t >> x;
			--s;
			lst.add(s, t, x);
		}
		else {
			int s, t;
			cin >> s >> t;
			--s;
			cout << lst.getSum(s, t) << endl;
		}
	}
	return 0;
}
