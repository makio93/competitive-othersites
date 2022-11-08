// 本番AC

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
		string s;
		cin >> n >> s;
		int zcnt = count(all(s), '0');
		ll res = (zcnt==0 || zcnt==n) ? (ll)(n)*n : (ll)zcnt*(n-zcnt);
		vector<pair<char, int>> runs;
		runs.emplace_back(s[0], 1);
		rep3(i, 1, n) {
			if (runs.back().first == s[i]) runs.back().second++;
			else runs.emplace_back(s[i], 1);
		}
		for (const auto& pi : runs) res = max(res, (ll)pi.second*pi.second);
		cout << res << endl;
	}
	return 0;
}
