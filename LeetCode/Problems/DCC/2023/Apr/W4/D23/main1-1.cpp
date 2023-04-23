// 解説AC1(メモ化再帰)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<ll> dp(n+1, -1);
        auto calc = [&](auto& calc, int id=0) -> ll {
            if (dp[id] != -1) return dp[id];
            if (id >= n) return dp[id] = 1;
            if (s[id] == '0') return dp[id] = 0;
            ll val = s[id] - '0', rval = 0;
            for (int i=id; i<n; ++i) {
                if (val > (ll)k) break;
                rval = (rval + calc(calc, i+1)) % mod;
                if (i+1 < n) val = val * 10 + s[i+1] - '0';
            }
            return dp[id] = rval;
        };
        return (int)calc(calc);
    }
};
