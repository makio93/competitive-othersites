// 練習0,自力AC

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
	int n;
	cin >> n;
	vector<int> r(n), c(n);
	rep(i, n) cin >> r[i] >> c[i];
	vector<vector<int>> dp(n, vector<int>(n, INF));
	rep(i, n) dp[i][i] = 0;
	rep3(k, 1, n) for (int i=0; i+k<n; ++i) for (int j=i+1; j<=i+k; ++j) {
		dp[i][i+k] = min(dp[i][i+k], dp[i][j-1]+dp[j][i+k]+r[j]*r[i]*c[i+k]);
	}
	cout << dp[0][n-1] << endl;
	return 0;
}
