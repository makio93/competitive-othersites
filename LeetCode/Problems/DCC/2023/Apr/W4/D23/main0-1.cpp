// 自力AC1(貰うDP)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.length(), klen = (int)(to_string(k).length());
        vector<ll> dp(n+1);
        dp[0] = 1;
        for (int i=0; i<n; ++i) {
            int li = i;
            while (li >= 0 && i-li+1 <= klen && stoll(s.substr(li, i-li+1)) <= (ll)k) {
                if (s[li] != '0') dp[i+1] = (dp[i+1] + dp[li]) % mod;
                --li;
            }
        }
        return (int)dp[n];
    }
};
