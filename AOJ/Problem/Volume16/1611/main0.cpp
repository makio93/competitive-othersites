// 復習2回目,自力AC

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
        rep3(k, 1, n) for (int l=0; l+k<n; ++l) {
            int r = l + k;
            rep3(c, l+1, r+1) dp[l][r] = max(dp[l][r], dp[l][c-1]+dp[c][r]);
            if (dp[l+1][r-1]==k-1 && abs(w[l]-w[r])<=1) dp[l][r] = max(dp[l][r], dp[l+1][r-1]+2); 
        }
        cout << dp[0][n-1] << endl;
    }
    return 0;
}
