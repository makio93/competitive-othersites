// 解説AC3

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(4, -INF);
        dp[n%4] = 0;
        for (int i=n-1; i>=0; --i) {
            dp[i%4] = -INF;
            int sum = 0;
            for (int j=0; j<3&&i+j<n; ++j) {
                sum += stoneValue[i+j];
                dp[i%4] = max(dp[i%4], sum-dp[(i+j+1)%4]);
            }
        }
        return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
    }
};
