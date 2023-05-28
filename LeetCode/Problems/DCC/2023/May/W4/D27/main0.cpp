// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, -INF)));
        for (int i=n; i>=0; --i) for (int j=0; j<3; ++j) {
            if (i == n) {
                dp[i][j][0] = dp[i][j][1] = 0;
                continue;
            }
            dp[i][j][1] = INF;
            int sum = 0;
            for (int j2=0; j2<3&&i+j2<n; ++j2) {
                sum += stoneValue[i+j2];
                dp[i][j][0] = max(dp[i][j][0], dp[i+j2+1][j2][1]+sum);
                dp[i][j][1] = min(dp[i][j][1], dp[i+j2+1][j2][0]);
            }
        }
        int vsum = accumulate(stoneValue.begin(), stoneValue.end(), 0), bval = vsum - dp[0][0][0];
        return (dp[0][0][0] > bval) ? "Alice" : bval > dp[0][0][0] ? "Bob" : "Tie";
    }
};
