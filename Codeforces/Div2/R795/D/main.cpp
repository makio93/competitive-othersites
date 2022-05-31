// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll LINF = (ll)(1e18);

struct SegmentTree {
	int n;
	vector<ll> dat;
	SegmentTree() { init(1); }
	SegmentTree(int n_) { init(n_); }
	void init(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		dat = vector<ll>(2*n-1, LINF);
	}
	void update(int k, ll a) {
		k += n-1;
		dat[k] = a;
		while (k > 0) {
			k = (k-1) / 2;
			dat[k] = min(dat[k*2+1], dat[k*2+2]);
		}
	}
	ll query(int a, int b, int k=0, int l=0, int r=-1) {
		if (r == -1) { r = n; k = 0; l = 0; }
		if (r<=a || b<=l) return LINF;
		if (a<=l && r<=b) return dat[k];
		else {
			ll vl = query(a, b, k*2+1, l, (l+r)/2);
			ll vr = query(a, b, k*2+2, (l+r)/2, r);
			return min(vl, vr);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		vector<ll> s(n+1);
		rep(i, n) s[i+1] += s[i] + a[i];
		SegmentTree segt(n+2);
		rep(i, n+1) segt.update(i, s[i]);
		stack<tuple<ll, int, ll>> st;
		set<pair<ll, int>> vst;
		bool ok = true;
		rep(i, n) {
			while (!st.empty() && get<0>(st.top())<=(ll)a[i]) {
				vst.erase(make_pair(get<2>(st.top()), get<1>(st.top())));
				st.pop();
			}
			int lid = 0;
			if (!st.empty()) lid = get<1>(st.top());
			vst.emplace((ll)a[i]+segt.query(lid, i+1), i+1);
			if (vst.begin()->first < s[i+1]) {
				ok = false;
				break;
			}
			st.emplace((ll)a[i], i+1, (ll)a[i]+segt.query(lid, i+1));
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
