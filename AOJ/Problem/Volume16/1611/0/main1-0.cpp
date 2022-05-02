// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> w(n);
		rep(i, n) cin >> w[i];
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i=0; i+1<n; ++i) dp[i][i+1] = (abs(w[i]-w[i+1]) <= 1) ? 2 : 0;
		for (int k=3; k<=n; ++k) for (int i=0; i+k-1<n; ++i) {
			for (int j=0; j+1<k; ++j) dp[i][i+k-1] = max(dp[i][i+k-1], dp[i][i+j]+dp[i+j+1][i+k-1]);
			if (dp[i+1][i+k-2]==k-2 && abs(w[i]-w[i+k-1])<=1) dp[i][i+k-1] = max(dp[i][i+k-1], dp[i+1][i+k-2]+2);
		}
		cout << dp[0][n-1] << endl;
	}
	return 0;
}
