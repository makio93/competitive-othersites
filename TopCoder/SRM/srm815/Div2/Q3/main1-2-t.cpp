// 解説実装2-t,TLE

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
        unordered_map<int, int> dp;
        dp[0] = 0;
        rep(i, n) {
            auto ndp = dp;
            int bset = 0;
            rep(j, m) if (keys[i][j] == '^') bset |= (1<<j);
            for (auto pi : dp) if (!(pi.first&bset)) {
                if (ndp.find(pi.first|bset) == ndp.end()) ndp[pi.first|bset] = pi.second + 1;
                else ndp[pi.first|bset] = max(ndp[pi.first|bset], pi.second+1);
            }
            swap(ndp, dp);
        }
        int res = 0;
        for (auto pi : dp) res = max(res, pi.second);
        return res;
    }
};
