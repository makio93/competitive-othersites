// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;

class StepHopJumpMedium {
public:
    int countWays(string level) {
        int n = level.length();
        vector<ll> dp(n);
        dp[0] = 1;
        rep(i, n-1) {
            if (level[i] == '*') continue;
            if (i+1<n && level[i+1]=='-') dp[i+1] = (dp[i+1] + dp[i]) % mod;
            if (i+2<n && level[i+2]=='-') dp[i+2] = (dp[i+2] + dp[i]) % mod;
            if (i+3<n && level[i+3]=='-') dp[i+3] = (dp[i+3] + dp[i]) % mod;
        }
        return (int)(dp[n-1]);
    }
};
