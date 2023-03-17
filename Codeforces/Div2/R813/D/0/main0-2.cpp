// 本番WA2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		int res = 0;
		if (n == k) {
			cout << INF << endl;
			continue;
		}
		else if (k == 1) {
			set<pair<int, int>> avals;
			rep(i, n) avals.emplace(a[i], i);
			rep(i, n) {
				avals.erase({ a[i], i });
				int tval = 0;
				if (i-1 >= 0) tval = max(tval, a[i-1]);
				if (i+1 < n) tval = max(tval, a[i+1]);
				tval = min({ INF, tval, (avals.begin()->first)*2 });
				res = max(res, tval);
				avals.emplace(a[i], i);
			}
		}
		else {
			{
				set<pair<int, int>> avals;
				rep(i, n) avals.emplace(a[i], i);
				rep(i, n) {
					avals.erase({ a[i], i });
					int tval = 0;
					if (i-1 >= 0) tval = max(tval, a[i-1]);
					if (i+1 < n) tval = max(tval, a[i+1]);
					tval = min({ INF, tval, (avals.begin()->first)*2 });
					res = max(res, tval);
					avals.emplace(a[i], i);
				}
			}
			set<pair<int, int>> avals;
			rep(i, n) avals.emplace(a[i], i);
			rep(i, k-1) avals.erase(avals.begin());
			rep(i, n) {
				pair<int, int> tmp = { -1, -1 };
				if (avals.find({ a[i], i }) != avals.end()) {
					tmp = { a[i], i };
					avals.erase({ a[i], i });
				}
				else {
					tmp = *avals.begin();
					avals.erase(avals.begin());
				}
				int tval = 0;
				if (i-1>=0 && avals.find({a[i-1],i-1})!=avals.end()) tval = max(tval, a[i-1]);
				if (i+1<n && avals.find({a[i+1],i+1})!=avals.end()) tval = max(tval, a[i+1]);
				if (tval == 0) tval = INF;
				tval = min({ INF, tval, (avals.begin()->first)*2 });
				res = max(res, tval);
				avals.insert(tmp);
			}
			set<pair<int, int>> hst;
			rep(i, n) hst.emplace(a[i], i);
			rep(i, k-2) hst.erase(hst.begin());
			rep(i, n-1) {
				set<pair<int, int>> tmp;
				if (hst.find({ a[i], i }) != hst.end()) {
					tmp.emplace(a[i], i);
					hst.erase({ a[i], i });
				}
				if (hst.find({ a[i+1], i+1 }) != hst.end()) {
					tmp.emplace(a[i+1], i+1);
					hst.erase({ a[i+1], i+1 });
				}
				if (tmp.find({ a[i], i }) == tmp.end()) {
					tmp.insert(*hst.begin());
					hst.erase(hst.begin());
				}
				if (tmp.find({ a[i+1], i+1 }) == tmp.end()) {
					tmp.insert(*hst.begin());
					hst.erase(hst.begin());
				}
				res = max(res, min(INF, (hst.begin()->first)*2));
				for (auto pi : tmp) hst.insert(pi);
			}
		}
		cout << min(INF, res) << endl;
	}
	return 0;
}
