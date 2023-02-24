// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
class Never3Steps {
public:
    int count(int X, int Y) {
        vector<vector<vector<vector<ll>>>> dp(Y+2, vector<vector<vector<ll>>>(X+2, vector<vector<ll>>(2, vector<ll>(5))));
        dp[0][0][0][0] = 1;
        rep(i, Y+1) rep(j, X+1) {
            if (i==0 && j==0) {
                dp[i+1][j][0][1] = (dp[i+1][j][0][1] + dp[i][j][0][0]) % mod;
                dp[i][j+1][1][1] = (dp[i][j+1][1][1] + dp[i][j][0][0]) % mod;
                continue;
            }
            rep3(k, 1, 5) {
                int nk = min(4, k+1);
                dp[i+1][j][0][nk] = (dp[i+1][j][0][nk] + dp[i][j][0][k]) % mod;
                dp[i][j+1][1][nk] = (dp[i][j+1][1][nk] + dp[i][j][1][k]) % mod;
            }
            rep3(k, 1, 5) if (k != 3) {
                dp[i+1][j][0][1] = (dp[i+1][j][0][1] + dp[i][j][1][k]) % mod;
                dp[i][j+1][1][1] = (dp[i][j+1][1][1] + dp[i][j][0][k]) % mod;
            }
        }
        ll res = 0;
        rep(d, 2) rep(k, 5) if (k != 3) res = (res + dp[Y][X][d][k]) % mod;
        return (int)res;
    }
};
