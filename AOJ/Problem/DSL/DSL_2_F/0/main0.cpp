// 練習0,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int VMAX = (int)((1LL<<31) - 1);

struct LazySegTree {
	int n;
	vector<int> node, lazy;
	vector<bool> change;
	LazySegTree(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		node.resize(2*n-1, VMAX);
		lazy.resize(2*n-1, VMAX);
		change.resize(2*n-1);
	}
	void eval(int k, int l, int r) {
		if (change[k]) {
			node[k] = lazy[k];
			if (r-l > 1) {
				lazy[k*2+1] = lazy[k*2+2] = lazy[k];
				change[k*2+1] = change[k*2+2] = true;
			}
			change[k] = false;
		}
	}
	void update(int a, int b, int x, int k=0, int l=0, int r=-1) {
		if (r == -1) r = n;
		eval(k, l, r);
		if (r<=a || b<=l) return;
		if (a<=l && r<=b) {
			lazy[k] = x;
			change[k] = true;
			eval(k, l, r);
		}
		else {
			update(a, b, x, k*2+1, l, l+(r-l)/2);
			update(a, b, x, k*2+2, l+(r-l)/2, r);
			node[k] = min(node[k*2+1], node[k*2+2]);
		}
	}
	int find(int a, int b, int k=0, int l=0, int r=-1) {
		if (r == -1) r = n;
		eval(k, l, r);
		if (r<=a || b<=l) return VMAX;
		if (a<=l && r<=b) return node[k];
		else {
			int vl = find(a, b, k*2+1, l, l+(r-l)/2);
			int vr = find(a, b, k*2+2, l+(r-l)/2, r);
			return min(vl, vr);
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
			++t;
			lst.update(s, t, x);
		}
		else {
			int s, t;
			cin >> s >> t;
			++t;
			cout << lst.find(s, t) << endl;
		}
	}
	return 0;
}
