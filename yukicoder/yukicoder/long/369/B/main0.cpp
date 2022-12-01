// 本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353LL;
const string tar = "con";

int main() {
	int n, m;
	cin >> n;
	m = (n+2) / 3;
	vector<vector<ll>> dp(m+1, vector<ll>(3)), ndp;
	dp[0][2] = 1;
	rep(i, n) {
		ndp.assign(m+1, vector<ll>(3));
		rep(j, 26) {
			char tc = (char)('a'+j);
			size_t cid = tar.find(tc);
			rep(i2, m+1) rep(j2, 3) {
				int i1 = i2, j1 = j2;
				if (cid != string::npos) {
					if (cid>=1U && j2+1==(int)(cid)) ++j1;
					else if (cid==0U && j2==2) ++i1, j1 = 0;
				}
				if (i1 > m) continue;
				ndp[i1][j1] = (ndp[i1][j1] + dp[i2][j2]) % mod;
			}
		}
		swap(ndp, dp);
	}
	ll res = 0;
	rep3(i, 1, m+1) rep(j, 3) {
		if (j < 2) res = (res + dp[i][j] * (i-1) % mod) % mod;
		else res = (res + dp[i][j] * i % mod) % mod;
	}
	cout << res << endl;
	return 0;
}
