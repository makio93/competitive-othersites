// 復習1,自力AC

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
        rep(i, n-1) if (abs(w[i]-w[i+1]) <= 1) dp[i][i+1] = 2;
        rep3(k, 3, n+1) for (int i=0; i+k-1<n; ++i) {
            int r = i+k-1;
            for (int j=i+1; j<=r; ++j) dp[i][r] = max(dp[i][r], dp[i][j-1]+dp[j][r]);
            if (dp[i+1][r-1]==k-2 && abs(w[i]-w[r])<=1) dp[i][r] = max(dp[i][r], dp[i+1][r-1]+2);
        }
        cout << dp[0][n-1] << endl;
    }
    return 0;
}
