#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番中,未完成

const ll mod = 998244353;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> b(n);
    rep(i, n) cin >> b[i];
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(m+1, vector<ll>(4)));
    vector<vector<vector<ll>>> mul(n+1, vector<vector<ll>>(m+1, vector<ll>(4)));
    mul[1][1][0] = mul[1][1][2] = 1;
    rep3(i, 1, n) rep3(j, 1, m) {
        if (b[i-1][j-1] == 'o') {
            if (i-1>=1 && b[i-2][j-1]=='o') {
                // mul[i][j][0] 
                dp[i][j][0] = dp[i-1][j][1];
                dp[i][j][1] = (dp[i][j][1] + dp[i-1][j][0]) % mod;
            }
            if (j-1>=1 && b[i-1][j-2]=='o') {
                dp[i][j][2] = dp[i][j-1][3];
                dp[i][j][3] = (dp[i][j][3] + dp[i][j-1][2]) % mod;
            }
        }
    }
    return 0;
}
