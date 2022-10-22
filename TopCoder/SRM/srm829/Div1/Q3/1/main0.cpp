// 学習1回目,自力TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()
#define bit(x, i) (((x)>>(i))&1)

const ll mod = (ll)(1e9) + 7;
class UpdownNumbers {
public:
    int count(int D, int S) {
        vector<vector<ll>> dp(1<<10, vector<ll>(1<<10)), ndp;
        rep3(i, 1, 10) dp[1<<i][1<<i] = 1;
        rep(i, D-1) {
            ndp.assign(1<<10, vector<ll>(1<<10));
            rep(j1, 1<<10) rep(j2, 1<<10) rep(k, 10) {
                int tb1 = k, tb2 = k;
                while (tb1<10 && !bit(j1,tb1)) ++tb1;
                while (tb2>=0 && !bit(j2,tb2)) --tb2;
                int ti1 = (tb1 < 10) ? j1^(1<<tb1)^(1<<k) : j1^(1<<k), ti2 = (tb2 >= 0) ? j2^(1<<tb2)^(1<<k) : j2^(1<<k);
                ndp[ti1][ti2] += dp[j1][j2];
                ndp[ti1][ti2] %= mod;
            }
            swap(dp, ndp);
        }
        ll res = 0;
        rep(i1, 1<<10) rep(i2, 1<<10) if (__builtin_popcount(i1)>=S && __builtin_popcount(i2)>=S) {
            res += dp[i1][i2];
            res %= mod;
        }
        return (int)res;
    }
};
