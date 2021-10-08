// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class EllysKeys {
public:
    int getMax(vector<string> keys) {
        int n = keys.size(), m = keys.front().length();
        vector<int> dp((1<<m));
        rep(i, n) {
            auto ndp = dp;
            int bi = 0;
            rep(j, m) if (keys[i][j] == '^') bi |= (1<<j);
            rep(j, (1<<m)) if (!(j&bi)) {
                ndp[j|bi] = max(ndp[j|bi], dp[j]+1);
            }
            swap(ndp, dp);
        }
        int res = 0;
        rep(i, (1<<m)) res = max(res, dp[i]);
        return res;
    }
};
