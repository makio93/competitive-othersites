// 解説AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n+1);
        for (int i=n-1; i>=0; --i) {
            dp[i] = questions[i][0];
            int ri = min(n, i+questions[i][1]+1);
            dp[i] += dp[ri];
            dp[i] = max(dp[i], dp[i+1]);
        }
        return dp[0];
    }
};
