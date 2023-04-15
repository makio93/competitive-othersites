// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<int> dp(k+1, -INF);
        dp[0] = 0;
        for (int i=0; i<n; ++i) for (int j=k-1; j>=0; --j) {
            if (dp[j] == -INF) continue;
            int val = 0, cost = 0;
            for (const int& vi : piles[i]) {
                val += vi;
                ++cost;
                if (j+cost > k) break;
                dp[j+cost] = max(dp[j+cost], dp[j]+val);
            }
        }
        return dp[k];
    }
};
