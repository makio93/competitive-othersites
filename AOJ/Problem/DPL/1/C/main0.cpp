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
	int n, w;
	cin >> n >> w;
	vector<int> vi(n), wi(n);
	rep(i, n) cin >> vi[i] >> wi[i];
	vector<int> dp(w+1, -INF);
	dp[0] = 0;
	rep(i, n) rep(j, w+1-wi[i]) if (dp[j] != -INF) dp[j+wi[i]] = max(dp[j+wi[i]], dp[j]+vi[i]);
	int res = 0;
	rep(i, w+1) res = max(res, dp[i]);
	cout << res << endl;
	return 0;
}
