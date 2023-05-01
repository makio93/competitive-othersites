// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<int> dp(n+2);
        for (int i=n-1; i>=0; --i) for (int j=1; j<=n; ++j) dp[j] = max(dp[j], dp[j+1]+satisfaction[i]*j);
        return dp[1];
    }
};
