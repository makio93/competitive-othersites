// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int mod = (int)(1e9) + 7;
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1);
        int res = 0;
        dp[0] = 1;
        for (int i=1; i<=high; ++i) {
            if (i-zero >= 0) dp[i] = (dp[i] + dp[i-zero]) % mod;
            if (i-one >= 0) dp[i] = (dp[i] + dp[i-one]) % mod;
            if (i>=low && i<=high) res = (res + dp[i]) % mod;
        }
        return res;
    }
};
