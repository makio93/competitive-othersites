#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ後,自力AC

struct SegmentTree {
	int n;
	vector<pair<ll, int>> dat;
	SegmentTree() { init(1); }
	SegmentTree(int n_) { init(n_); }
	void init(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		dat = vector<pair<ll, int>>(2*n-1, { 0LL, -1 });
	}
	void update(int k, ll a) {
		int tk = k;
		k += n-1;
		dat[k] = { a, tk };
		while (k > 0) {
			k = (k-1) / 2;
			dat[k] = max(dat[k*2+1], dat[k*2+2]);
		}
	}
	pair<ll, int> query(int a, int b, int k=0, int l=0, int r=-1) {
		if (r == -1) { r = n; k = 0; l = 0; }
		if (r<=a || b<=l) return { 0LL, -1 };
		if (a<=l && r<=b) return dat[k];
		else {
			auto vl = query(a, b, k*2+1, l, (l+r)/2);
			auto vr = query(a, b, k*2+2, (l+r)/2, r);
			return max(vl, vr);
		}
	}
};

int main() {
	ll n;
	int m;
	cin >> n >> m;
	vector<ll> a(m);
	rep(i, m) cin >> a[i];
	SegmentTree ta(m+2);
	rep(i, m) ta.update(i, a[i]);
	int q;
	cin >> q;
	rep(i, q) {
		int ti, xi;
		ll yi;
		cin >> ti >> xi >> yi;
		--xi;
		if (ti == 1) {
			ll pyi = ta.query(xi, xi+1).first;
			ta.update(xi, pyi+yi);
		}
		else if (ti == 2) {
			ll pyi = ta.query(xi, xi+1).first;
			ta.update(xi, pyi-yi);
		}
		else {
			int res = ta.query(0, m).second + 1;
			cout << res << endl;
		}
	}
	return 0;
}
