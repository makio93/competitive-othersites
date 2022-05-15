// 自力AC

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
	int q;
	cin >> q;
	rep(i0, q) {
		string x, y;
		cin >> x >> y;
		int n = x.length(), m = y.length();
		vector<vector<int>> dp(n+1, vector<int>(m+1));
		rep(i, n) rep(j, m) {
			dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			if (x[i] == y[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}
