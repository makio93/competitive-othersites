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
		int n;
		cin >> n;
		vector<int> b(n);
		rep(i, n) cin >> b[i];
		vector<int> memo(n+1, -INF);
		auto calc = [&](int di) -> int {
			if (memo[di] != -INF) return memo[di];
			set<pair<int, int>> mst;
			int val = 0;
			rep(i, n) {
				mst.emplace(b[i], i);
				if (i-di-1 >= 0) mst.erase({b[i-di-1], i-di-1});
				int sum = 0, cnt = 0;
				for (auto itr=mst.rbegin(); cnt<3&&itr!=mst.rend(); ++itr,++cnt) sum += itr->first;
				val = max(val, sum);
			}
			return memo[di] = val - di;
		};
		int li = 2, ri = n-1, lval = calc(li), rval = calc(ri);
		while (ri-li >= 3) {
			int cli = li + (ri-li) / 3, cri = ri - (ri-li) / 3, clval = calc(cli), crval = calc(cri);
			if (max(lval, rval) >= max(clval, crval)) {
				if (lval >= rval) {
					ri = cri;
					rval = crval;
				}
				else {
					li = cli;
					lval = clval;
				}
			}
			else {
				if (clval >= crval) {
					ri = cri;
					rval = crval;
				}
				else {
					li = cli;
					lval = clval;
				}
			}
		}
		if (ri-li == 2) calc(li+1);
		cout << (*max_element(all(memo))) << endl;
	}
	return 0;
}
