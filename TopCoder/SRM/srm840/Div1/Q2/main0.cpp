// 終了後,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;

class AlternatingPermutations {
public:
    int count(int n, vector<int> prefix) {
        int m = prefix.size();
        vector<bool> used(n);
        bool ok = true;
        rep(i, m) {
            if (used[prefix[i]]) {
                ok = false;
                break;
            }
            used[prefix[i]] = true;
        }
        if (!ok) return 0;
        vector<int> sub(m);
        rep(i, m-1) sub[i] = prefix[i+1] - prefix[i];
        rep(i, m-2) if (sub[i]*sub[i+1] >= 0) {
            ok = false;
            break;
        }
        if (!ok) return 0;
        int lcnt = 0, hcnt = 0;
        if (!prefix.empty()) {
            rep(i, n) if (!used[i]) {
                if (i < prefix.back()) ++lcnt;
                else ++hcnt;
            }
        }
        else lcnt = n;
        if (m==n || n==1) return 1;
        int sval = 0;
        if (m-2 >= 0) {
            if (sub[m-2] > 0) sval = 1;
            else sval = -1;
        }
        vector<vector<ll>> dp(2, vector<ll>(n-m+2));
        dp[0][lcnt] = 1;
        dp[0][lcnt+1] = -1;
        rep(i, n-m+1) {
            rep(j, n-m+1) dp[i%2][j+1] = (dp[i%2][j+1] + dp[i%2][j]) % mod;
            if (i == n-m) continue;
            dp[(i+1)%2].assign(n-m+2, 0);
            rep(j, n-m+1) {
                int nc = n-m - i, hc = nc - j;
                if ((i%2==0) ^ (sval>=0)) {
                    if (hc > 0) {
                        dp[(i+1)%2][j] = (dp[(i+1)%2][j] + dp[i%2][j]) % mod;
                        dp[(i+1)%2][j+hc] = (dp[(i+1)%2][j+hc] - dp[i%2][j] + mod) % mod;
                    }
                }
                else {
                    if (j > 0) {
                        dp[(i+1)%2][0] = (dp[(i+1)%2][0] + dp[i%2][j]) % mod;
                        dp[(i+1)%2][j] = (dp[(i+1)%2][j] - dp[i%2][j] + mod) % mod;
                    }
                }
            }
        }
        ll res = 0;
        rep(i, n-m+1) res = (res + dp[(n-m)%2][i]) % mod;
        if (sval == 0) {
            if (m == 0) res = res * 2 % mod;
            else {
                dp.assign(2, vector<ll>(n-m+2));
                dp[0][lcnt] = 1;
                dp[0][lcnt+1] = -1;
                rep(i, n-m+1) {
                    rep(j, n-m+1) dp[i%2][j+1] = (dp[i%2][j+1] + dp[i%2][j]) % mod;
                    if (i == n-m) continue;
                    dp[(i+1)%2].assign(n-m+2, 0);
                    rep(j, n-m+1) {
                        int nc = n-m - i, hc = nc - j;
                        if ((i%2==0) ^ (!(sval>=0))) {
                            if (hc > 0) {
                                dp[(i+1)%2][j] = (dp[(i+1)%2][j] + dp[i%2][j]) % mod;
                                dp[(i+1)%2][j+hc] = (dp[(i+1)%2][j+hc] - dp[i%2][j] + mod) % mod;
                            }
                        }
                        else {
                            if (j > 0) {
                                dp[(i+1)%2][0] = (dp[(i+1)%2][0] + dp[i%2][j]) % mod;
                                dp[(i+1)%2][j] = (dp[(i+1)%2][j] - dp[i%2][j] + mod) % mod;
                            }
                        }
                    }
                }
                rep(i, n-m+1) res = (res + dp[(n-m)%2][i]) % mod;
            }
        }
        return (int)res;
    }
};
