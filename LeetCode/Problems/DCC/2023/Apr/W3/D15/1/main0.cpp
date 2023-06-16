// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<int> dp(k+1, -1);
        dp[0] = 0;
        for (int i=0; i<n; ++i) {
            int m = piles[i].size();
            for (int j=k; j>=0; --j) {
                int sum = 0;
                for (int j2=0; j2<m; ++j2) {
                    if (j-j2-1 < 0) break;
                    sum += piles[i][j2];
                    if (dp[j-j2-1] != -1) dp[j] = max(dp[j], dp[j-j2-1]+sum);
                }
            }
        }
        return dp[k];
    }
};
