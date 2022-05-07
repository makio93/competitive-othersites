// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
class MagicNumberThree {
public:
    int countSubsequences(string s) {
        int n = s.length();
        vector<vector<ll>> dp(n+1, vector<ll>(3));
        dp[0][0] = 1;
        rep(i, n) rep(j, 3) {
            dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
            dp[i+1][(j+(s[i]-'0'))%3] = (dp[i+1][(j+(s[i]-'0'))%3] + dp[i][j]) % mod;
        }
        return (dp[n][0] - 1 + mod) % mod;
    }
};
