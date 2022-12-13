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
		int m;
		cin >> m;
		vector<string> c(2);
		rep(i, 2) cin >> c[i];
		vector<vector<bool>> dp(2, vector<bool>(m+1));
		dp[0][0] = dp[1][0] = true;
		rep(i, m) {
			if (c[0][i]=='B' && c[1][i]=='B') {
				dp[0][i+1] = dp[1][i];
				dp[1][i+1] = dp[0][i];
			}
			else if (c[0][i] == 'B') dp[0][i+1] = dp[0][i];
			else dp[1][i+1] = dp[1][i];
		}
		if (dp[0][m] || dp[1][m]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
