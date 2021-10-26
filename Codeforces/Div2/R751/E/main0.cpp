#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番,未完成,WA

struct SegmentTree {
	int n;
	vector<pair<int, int>> dat;
	SegmentTree() { init(1); }
	SegmentTree(int n_) { init(n_); }
	void init(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		dat = vector<pair<int, int>>(2*n-1, { 0, -1 });
	}
	void update(int k, int a) {
		int id = k;
		k += n-1;
		dat[k].first += a;
		dat[k].second = id;
		while (k > 0) {
			k = (k-1) / 2;
			dat[k] = min(dat[k*2+1], dat[k*2+2]);
		}
	}
	pair<int, int> query(int a, int b, int k=0, int l=0, int r=-1) {
		if (r == -1) { r = n; k = 0; l = 0; }
		if (r<=a || b<=l) return { (int)(1e9), -1 };
		if (a<=l && r<=b) return dat[k];
		else {
			pair<int, int> vl = query(a, b, k*2+1, l, (l+r)/2);
			pair<int, int> vr = query(a, b, k*2+2, (l+r)/2, r);
			return min(vl, {vl.first+vr.first,vr.second});
		}
	}
};

struct BIT {
	int n;
	vector<ll> d;
	BIT(int n=0) : n(n), d(n+1) {}
	void add(int i, ll x=1) {
		for (i++; i<=n; i+=i&-i) {
			d[i] += x;
		}
	}
	ll sum(int i) {
		ll x = 0;
		for (i++; i; i-=i&-i) {
			x += d[i];
		}
		return x;
	}
	ll sum(int l, int r) {
		return sum(r-1) - sum(l-1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		rep(i, n) cin >> a[i];
		rep(i, m) cin >> b[i];
		vector<pair<int, int>> vlst;
		rep(i, n) vlst.emplace_back(a[i], i);
		unordered_map<int, int> blst;
		rep(i, m) {
			if (blst.find(b[i]) == blst.end()) blst[b[i]] = -1;
			else blst[b[i]]--;
		}
		for (auto bi : blst) vlst.emplace_back(bi);
		sort(all(vlst));
		SegmentTree st(n);
		rep(i, n) st.update(i, 1);
		int vlen = vlst.size();
		unordered_map<int, unordered_map<int, int>> bids;
		rep(i, vlen) {
			if (vlst[i].second >= 0) {
				int aid = vlst[i].second;
				st.update(aid, -2);
			}
			else {
				int bcnt = -vlst[i].second;
				auto rval = st.query(0, n);
				int bid = rval.second - 1;
				bids[bid][vlst[i].first] += bcnt;
				st.update(bid, -bcnt*2);
			}
		}
		vector<int> clst;
		rep(i, n) {
			clst.push_back(a[i]);
			if (bids.find(i) != bids.end()) {
				for (auto bi : bids[i]) rep(j, bi.second) clst.push_back(bi.first);
			}
		}
		int clen = clst.size();
		vector<pair<int, int>> cvals;
		rep(i, clen) cvals.emplace_back(clst[i], i);
		sort(cvals.rbegin(), cvals.rend());
		BIT bt(clen);
		ll res = 0;
		rep(i, clen) {
			bt.add(cvals[i].second, 1);
			res += bt.sum(cvals[i].second-1);
		}
		cout << res << endl;
	}
	return 0;
}
