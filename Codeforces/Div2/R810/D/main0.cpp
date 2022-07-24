// 本番WA

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
		int n, m;
		cin >> n >> m;
		vector<int> x(n), p(n);
		rep(i, n) cin >> x[i] >> p[i];
		map<int, unordered_set<int>> ids;
		rep(i, n) {
			ids[x[i]-p[i]].insert(1);
			ids[x[i]].insert(-i);
			ids[x[i]+p[i]].insert(2);
		}
		int sub = 0, fcnt = 0;
		ll nval = 0;
		vector<bool> res(n);
		auto itr = ids.begin();
		for (int tval : itr->second) {
			if (tval > 0) ++sub;
			else sub -= 2;
		}
		for (auto itr=next(ids.begin()); itr!=ids.end(); ++itr) {
			nval += sub * (ll)(itr->first-prev(itr)->first);
			for (int tval : itr->second) {
				if (tval > 0) ++sub;
				else {
					sub -= 2;
					if (nval>m && nval-p[-tval]<=m) res[-tval] = true;
					if (nval>m && nval-p[-tval]>m) ++fcnt;
				}
			}
		}
		if (fcnt >= 1) cout << string(n, '0') << endl;
		else {
			string ans;
			rep(i, n) {
				if (res[i]) ans.push_back('1');
				else ans.push_back('0');
			}
			cout << ans << endl;
		}
	}
	return 0;
}
