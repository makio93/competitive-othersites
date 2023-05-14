// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n+1);
        for (int i=0; i<n; ++i) {
            dp[i+1] = max(dp[i+1], dp[i]);
            int ri = min(n, i+questions[i][1]+1);
            dp[ri] = max(dp[ri], dp[i]+questions[i][0]);
        }
        return dp[n];
    }
};
