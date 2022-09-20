// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll LINF = (ll)(1e18);

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
		ll res = 0;
		if (k == 1) {
			res = *max_element(all(a));
			cout << res << endl;
			continue;
		}
		vector<vector<ll>> dp;
		for (int i=0; i+k-1<n; ++i) {
			dp.assign(k+1, vector<ll>(k+1));
			rep(ii, k) {
				vector<ll> vals;
				int pid = i+ii;
				vals.push_back(a[pid]);
				for (int jj=1; pid+jj*k<n; ++jj) vals.push_back(a[pid+jj*k]);
				for (int jj=1; pid-jj*k>=0; ++jj) {
					if (jj >= (int)(vals.size())) vals.push_back(a[pid-jj*k]);
					else vals[jj] = max(vals[jj], (ll)a[pid-jj*k]);
				}
				int vlen = vals.size();
				rep(jj, vlen-1) vals[jj+1] = max(vals[jj+1], vals[jj]);
				rep(jj, k+1) {
					rep(jj2, vlen) {
						if (jj-jj2 < 0) break;
						dp[ii+1][jj] = max(dp[ii+1][jj], dp[ii][jj-jj2]+vals[jj2]);
					}
					if (jj-1 >= 0) dp[ii+1][jj] = max(dp[ii+1][jj], dp[ii+1][jj-1]);
				}
			}
			ll val = 0;
			rep(ii, k+1) val = max(val, dp[k][ii]);
			res = max(res, val);
			res = max(res, accumulate(a.begin()+i, a.begin()+i+k, 0LL));
		}
		cout << res << endl;
	}
	return 0;
}
