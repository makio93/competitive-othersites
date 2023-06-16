// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector dp(n+1, vector(k+1, 0));
        for (int i=0; i<n; ++i) for (int j=0; j<=k; ++j) {
            int sum = 0;
            for (int j2=0; j2<=min((int)(piles[i].size()),j); ++j2) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-j2]+sum);
                if (j2 < (int)(piles[i].size())) sum += piles[i][j2];
            }
        }
        return dp[n][k];
    }
};
