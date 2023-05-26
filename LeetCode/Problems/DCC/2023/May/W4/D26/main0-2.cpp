// 自力AC2

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n, vector<int>(2, 0)));
        for (int i=n-1; i>=0; --i) for (int j=0; j<n; ++j) {
            dp[i][j][1] = INF;
            int ri = min(n-i, 2*(j+1)), sum = 0;
            for (int j2=0; j2<ri; ++j2) {
                int ti = max(j2+1, j+1) - 1;
                sum += piles[i+j2];
                dp[i][j][0] = max(dp[i][j][0], dp[i+j2+1][ti][1]+sum);
                dp[i][j][1] = min(dp[i][j][1], dp[i+j2+1][ti][0]);
            }
        }
        return dp[0][0][0];
    }
};
