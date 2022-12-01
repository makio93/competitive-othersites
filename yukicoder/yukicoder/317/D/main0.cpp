#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番AC

const ll mod = (ll)(1e9) + 7;
const string tar = "yukicoder";

int main() {
	int n;
	string s;
	cin >> n >> s;
	int m = tar.length();
	vector<vector<ll>> dp(2, vector<ll>(m+1));
	dp[0][0] = 1;
	rep(i, n) {
		int sid = -1;
		rep(j, m) if (s[i] == tar[j]) sid = j;
		if (sid==-1 && s[i]!='?') continue;
		auto ndp = dp;
		if (sid==-1 && s[i]=='?') rep(j, m) ndp[1][j+1] = (ndp[1][j+1] + dp[0][j]) % mod;
		else rep(j, 2) ndp[j][sid+1] = (ndp[j][sid+1] + dp[j][sid]) % mod;
		swap(ndp, dp);
	}
	ll res = 0;
	rep(i, 2) res = (res + dp[i][m]) % mod;
	cout << res << endl;
	return 0;
}
