// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353LL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<ll> dp(n+1), res(n+1);
	dp[0] = res[0] = 1;
	vector<ll> ndp(n+1);
	int sval = 0;
	rep3(i, k, n+1) {
		ndp.assign(n+1, 0);
		if (sval+i > n) break;
		for (int j=sval; j+i<=n; ++j) {
			ndp[j+i] = (ndp[j+i] + dp[j]) % mod;
			dp[j+i] = (dp[j+i] + dp[j]) % mod;
		}
		for (int j=sval; j<=n; ++j) res[j] = (res[j] + ndp[j]) % mod;
		swap(ndp, dp);
		sval += i;
	}
	rep3(i, 1, n+1) cout << res[i] << (i<=n-1?' ':'\n');
	return 0;
}
