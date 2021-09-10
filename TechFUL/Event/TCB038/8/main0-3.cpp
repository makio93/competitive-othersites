#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1)));
    dp[0][0][0] = 1;
    for (int k=0; k<=n-1; ++k) {
        for (int k2=1; k+k2<=n; ++k2) if (k2%m != 0) dp[1][1][k+k2] += dp[0][0][k];
        ll sub = 0;
        for (int k1=0; k1<=k-1; k1+=m) sub += dp[0][0][k1];
        dp[0][1][k] -= sub;
    }
    for (int r=2; r<=n; ++r) {
        for (int k=0; k<=n-1; ++k) {
            for (int k2=1; k+k2<=n; ++k2) if (k2%m != 0) dp[r][r][k+k2] += dp[1][r-1][k];
        }
        for (int l=r-1; l>0; --l) {
            for (int k=1; k<=n; ++k) if (k%m != 0) {
                for (int k2=1; k2+1<=k; ++k2) if (k2%m!=0 && (k-k2)%m!=0) {
                    dp[l][r][k] += dp[l][l][k2] * dp[l+1][r][k-k2];
                }
                ll sub = 0;
                for (int k1=0; k1<=k-1; k1+=m) sub += dp[1][l-1][k1] * dp[l][l][k1] * dp[l+1][r][k1];
                dp[l][r][k] -= sub;
            }
        }
    }
    ll res = 0;
    for (int i=1; i<=n; ++i) res += dp[1][i][n];
    cout << res << endl;
    return 0;
}
