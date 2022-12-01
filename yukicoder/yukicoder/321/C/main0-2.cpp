#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

const ll mod = (ll)(1e9) + 7;

int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	if (k == 1) {
		ll res = 1;
		rep(i, n) res = res * 2 % mod;
		res = (res - 1 + mod) % mod;
		cout << res << endl;
		return 0;
	}
	vector<pair<int, int>> kpvec;
	int ktmp = k;
	for (int i=2; i*i<=ktmp; ++i) if (ktmp%i == 0) {
		kpvec.emplace_back(i, 0);
		while (ktmp%i == 0) {
			kpvec.back().second++;
			ktmp /= i;
		}
	}
	if (ktmp > 1) kpvec.emplace_back(ktmp, 1);
	int m = kpvec.size();
	map<vector<pair<int, int>>, ll> dp;
	rep(i, n) {
		vector<pair<int, int>> aip;
		ll atmp = a[i];
		for (auto pi : kpvec) {
			aip.emplace_back(pi.first, 0);
			while (atmp%pi.first == 0) {
				aip.back().second++;
				atmp /= pi.first;
			}
			aip.back().second = min(aip.back().second, pi.second);
		}
		map<vector<pair<int, int>>, ll> ndp;
		ndp[aip] = (ndp[aip] + 1) % mod;
		for (auto pi : dp) {
			auto naip = pi.first;
			rep(j, m) naip[j].second = min(naip[j].second+aip[j].second, kpvec[j].second);
			ndp[naip] = (ndp[naip] + pi.second) % mod;
		}
		for (auto pi : ndp) dp[pi.first] = (dp[pi.first] + pi.second) % mod;
	}
	cout << dp[kpvec] << endl;
	return 0;
}
