#include <bits/stdc++.h>
using namespace std;

// 解説AC2,DP,貰うDP

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        for (int i=1; i<=n; ++i) for (int j=1; j*j<=i; ++j) {
            if (!dp[i-j*j]) {
                dp[i] = true;
                break;
            }
        }
        return dp[n];
    }
};
