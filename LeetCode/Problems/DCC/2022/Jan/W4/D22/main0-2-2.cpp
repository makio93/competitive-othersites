#include <bits/stdc++.h>
using namespace std;

// 自力AC,ヒントあり,DP解法,添え字下から遷移する

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        for (int i=1; i<=n; ++i) for (int j=(int)round(sqrt(i)); j>0; --j) {
            if (i-j*j < 0) continue;
            dp[i] = dp[i] | (!dp[i-j*j]);
            if (dp[i]) break;
        }
        return dp[n];
    }
};
