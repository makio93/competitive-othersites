// 本番中,未完成,解答不能

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
        vector<vector<vector<ll>>> dp(D, vector<vector<ll>>(S*S, vector<ll>(10*10)));
        rep3(i, 1, 10) dp[0][0*S+0][i*10+i] = 1;
        rep(i, D-1) rep(j1, S) rep(j2, S) rep(k1, 10) rep(k2, 10) {
            auto ndp = dp;
            // rep3(t1, k1+1, k2) ndp[i+1][min(S-1,j1+1)*S+min(S-1,j2+1)][t1*10+]
        }
    }
};
