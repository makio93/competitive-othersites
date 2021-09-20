#include <bits/stdc++.h>
using namespace std;

// 解説AC2

using ull = unsigned long long;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<ull> dp(m+1);
        dp[0] = 1;
        for (int i=0; i<n; ++i) {
            auto pre = dp[0];
            for (int j=0; j<m; ++j) {
                auto tmp = dp[j+1];
                if (s[i] == t[j]) dp[j+1] += pre;
                swap(pre, tmp);
            }
        }
        return (int)dp[m];
    }
};
