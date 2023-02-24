// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class FeedADrake {
public:
    int feed(int stomach, vector<int> cakes, int excess) {
        int n = cakes.size(), res = 0;
        if (n <= excess) {
            res = accumulate(all(cakes), 0);
            return res;
        }
        sort(all(cakes));
        vector<bool> dp(stomach), ndp;
        dp[0] = true;
        rep(i, n-excess) {
            ndp.assign(stomach, false);
            rep(j, stomach) if (dp[j]) {
                ndp[j] = true;
                res = max(res, j+cakes[i]);
                if (j+cakes[i] < stomach) ndp[j+cakes[i]] = true;
            }
            swap(ndp, dp);
        }
        rep3(i, n-excess, n) res += cakes[i];
        return res;
    }
};
