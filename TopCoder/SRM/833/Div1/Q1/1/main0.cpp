// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
const vector<int> di = { 0, 1 }, dj = { 1, 0 };

class Never3Steps {
public:
    int count(int X, int Y) {
        vector<vector<vector<vector<ll>>>> dp(X+1, vector<vector<vector<ll>>>(Y+1, vector<vector<ll>>(2, vector<ll>(5))));
        dp[0][0][0][0] = 1;
        rep(i, X+1) rep(j, Y+1) rep(i1, 2) rep(j1, 5) rep(i2, 2) {
            if (j1==3 && i2!=i1) continue;
            int j2 = (i2 == i1) ? min(4, j1+1) : 1, ni = i + di[i2], nj = j + dj[i2];
            if (ni>X || nj>Y) continue;
            dp[ni][nj][i2][j2] += dp[i][j][i1][j1];
            dp[ni][nj][i2][j2] %= mod;
        }
        ll res = 0;
        rep(i, 2) rep(j, 5) if (j != 3) res = (res + dp[X][Y][i][j]) % mod;
        return (int)res;
    }
};
