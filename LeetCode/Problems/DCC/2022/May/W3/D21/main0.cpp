// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, INF);
        dp[0] = 0;
        for (int i=0; i<n; ++i) for (int j=0; j+coins[i]<=amount; ++j) 
            if (dp[j] != INF) dp[j+coins[i]] = min(dp[j+coins[i]], dp[j]+1);
        return dp[amount] == INF ? -1 : dp[amount];
    }
};
