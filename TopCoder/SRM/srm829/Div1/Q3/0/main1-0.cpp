// 解説1-0,TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
class UpdownNumbers {
public:
    int count(int D, int S) {
        vector<vector<ll>> dp(1<<10, vector<ll>(1<<10));
        rep3(i, 1, 10) dp[1<<i][1<<(9-i)] += 1;
        rep3(i, 1, D) {
            vector<vector<ll>> ndp(1<<10, vector<ll>(1<<10));
            rep(i1, 1<<10) rep(j1, 1<<10) rep(i2, 10) {
                int lid = ((i1>>i2)&(-(i1>>i2)))<<i2, rid = ((j1>>(9-i2))&(-(j1>>(9-i2))))<<(9-i2);
                int b1 = (i1^lid)|(1<<i2), b2 = (j1^rid)|(1<<(9-i2));
                ndp[b1][b2] = (ndp[b1][b2] + dp[i1][j1]) % mod;
            }
            swap(ndp, dp);
        }
        ll res = 0;
        rep(i, 1<<10) rep(j, 1<<10) 
            if (__builtin_popcount(i)>=S && __builtin_popcount(j)>=S) 
                res = (res + dp[i][j]) % mod;
        return (int)res;
    }
};
