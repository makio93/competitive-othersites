// 本番TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        vector<unordered_map<int, ll>> memo(n+1);
        auto calc = [&](auto calc, int len, int mval) -> ll {
            if (memo[len].find(mval) != memo[len].end()) return memo[len][mval];
            if (mval == 1) return memo[len][mval] = 1;
            if (len == 1) return memo[len][mval] = mval;
            ll ret = 0;
            for (int i=1; i<=mval; ++i) ret = (ret + calc(calc, len-1, mval/i)) % mod;
            return memo[len][mval] = ret;
        };
        return (int)calc(calc, n, maxValue);
    }
};
