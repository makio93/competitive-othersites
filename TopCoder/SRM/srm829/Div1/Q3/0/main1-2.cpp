// 解説AC1-2

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
        vector<vector<int>> uto(1<<10, vector<int>(10)), dto(1<<10, vector<int>(10));
        rep(i, 1<<10) rep(j, 10) uto[i][j] = (i ^ (((i>>j) & -(i>>j)) << j)) | (1 << j);
        rep(i, 1<<10) rep(j, 10) dto[i][j] = (i ^ (((i>>(9-j)) & -(i>>(9-j))) << (9-j))) | (1 << (9-j));
        vector<vector<int>> dp(1<<10, vector<int>(1<<10)), ndp;
        rep3(i, 1, 10) dp[1<<i][1<<(9-i)] = 1;
        rep3(i, 1, D) {
            ndp.assign(1<<10, vector<int>(1<<10));
            rep(i1, 1<<10) rep(j1, 1<<10) if (dp[i1][j1]) rep(i2, 10) ndp[uto[i1][i2]][dto[j1][i2]] = (ndp[uto[i1][i2]][dto[j1][i2]] + dp[i1][j1]) % mod;
            swap(ndp, dp);
        }
        ll res = 0;
        rep(i, 1<<10) rep(j, 1<<10) if (__builtin_popcount(i)>=S && __builtin_popcount(j)>=S) res = (res + dp[i][j]) % mod;
        return (int)res;
    }
};
