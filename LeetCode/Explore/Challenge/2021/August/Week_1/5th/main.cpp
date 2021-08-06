#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        dp[1][0] = piles[0];
        dp[0][1] = piles[n-1];
        for (int i=1; i<=n; ++i) {
            for (int l=0; l<=i; ++l) {
                int r = i - l;
                bool first = (i%2 == 1);
                if (l-1>=0 && r-1>=0) {
                    if (first) dp[l][r] = max(dp[l-1][r]+piles[l-1], dp[l][r-1]+piles[n-(r-1)-1]);
                    else dp[l][r] = min(dp[l-1][r]+piles[l-1], dp[l][r-1]+piles[n-(r-1)-1]);
                }
                else if (l-1 >= 0) dp[l][r] = dp[l-1][r] + piles[l-1];
                else dp[l][r] = dp[l][r-1] + piles[n-(r-1)-1];
            }
        }
        int sum = 0;
        for (int i=0; i<n; ++i) sum += piles[i];
        bool res = false;
        for (int i=0; i<=n; ++i) if (dp[i][n-i] > sum-dp[i][n-i]) res = true;
        return res;
    }
};
