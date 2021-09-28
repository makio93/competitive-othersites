#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

template<typename T>
struct BIT {
	int n;
	vector<T> d;
	BIT(int n=0) : n(n), d(n+1) {}
	void add(int i, T x=1) {
		for (i++; i<=n; i+=i&-i) {
			d[i] += x;
		}
	}
	T sum(int i) {
		T x = 0;
		for (i++; i; i-=i&-i) {
			x += d[i];
		}
		return x;
	}
	T sum(int l, int r) {
		return sum(r-1) - sum(l-1);
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
		set<int> b;
		rep(i, n) b.insert(a[i]);
		map<int, int> bid;
		for (int bi : b) bid[bi] = bid.size() + 1;
		vector<int> vcnt(b.size()+2);
		BIT<int> bcnt(b.size()+2);
		vcnt[bid[a[0]]]++;
		bcnt.add(bid[a[0]], 1);
		ll res = 0;
		rep3(i, 1, n) {
			int ncnt = vcnt[bid[a[i]]];
			int lcnt = bcnt.sum(bid[a[i]]-1);
			int rcnt = i - ncnt - lcnt;
			res += min(lcnt, rcnt);
			vcnt[bid[a[i]]]++;
			bcnt.add(bid[a[i]], 1);
		}
		cout << res << endl;
	}
	return 0;
}
