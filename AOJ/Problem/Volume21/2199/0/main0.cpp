// 練習0,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1.8e9);

int main() {
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n==0 && m==0) break;
		vector<int> c(m), x(n);
		rep(i, m) cin >> c[i];
		rep(i, n) cin >> x[i];
		vector<vector<int>> dp(n+1, vector<int>(256, INF));
		dp[0][128] = 0;
		rep(i, n) rep(j1, 256) if (dp[i][j1] != INF) rep(j2, m) {
			int val = min(255, max(0, j1+c[j2]));
			dp[i+1][val] = min(dp[i+1][val], dp[i][j1]+(val-x[i])*(val-x[i]));
		}
		int res = INF;
		rep(i, 256) if (dp[n][i] != INF) res = min(res, dp[n][i]);
		cout << res << endl;
	}
	return 0;
}
