// 復習1回目,自力AC

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
        vector<ll> dp(3);
        dp[0] = 1;
        rep(i, n) {
            auto ndp = dp;
            rep(j, 3) ndp[(j*10+(s[i]-'0'))%3] = (ndp[(j*10+(s[i]-'0'))%3] + dp[j]) % mod;
            swap(ndp, dp);
        }
        return (int)((dp[0]-1+mod)%mod);
    }
};
