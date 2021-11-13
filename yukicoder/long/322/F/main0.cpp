#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 終了後,自力AC

const ll mod = 998244353LL;

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<vector<ll>> dp(n+1, vector<ll>(2));
	vector<ll> cpow25(n+1, 1);
	rep(i, n) cpow25[i+1] = cpow25[i] * 25 % mod;
	repr(i, n) {
		if (s[i] == 'a') dp[i][1] = (dp[i][1] + dp[i+1][0]) % mod;
		else {
			int len1 = s[i] - 'b';
			dp[i][1] = (dp[i][1] + cpow25[n-(i+1)]) % mod;
			if (n-(i+1)-1 >= 0) dp[i][1] = (dp[i][1] + len1 * cpow25[n-(i+1)-1] * (n-(i+1)) % mod) % mod;
			dp[i][1] = (dp[i][1] + dp[i+1][1]) % mod;
			dp[i][0] = (dp[i][0] + len1 * cpow25[n-(i+1)] % mod) % mod;
			dp[i][0] = (dp[i][0] + dp[i+1][0]) % mod;
		}
	}
	cout << dp[0][1] << endl;
	return 0;
}
