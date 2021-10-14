#include <bits/stdc++.h>
using namespace std;

// 解説AC2,DP解法,dpテーブルを前計算

class Solution {
    int INF = (int)(1e9), N_MAX = (int)(1e4);
    void init(vector<int>& dp) {
        dp.assign(N_MAX+1, INF);
        dp[0] = 0;
        for (int i=1; i<=N_MAX; ++i) for (int j=1; j*j<=i; ++j) dp[i] = min(dp[i], dp[i-j*j]+1);
    }
public:
    int numSquares(int n) {
        static vector<int> dp;
        if (dp.empty()) init(dp);
        return dp[n];
    }
};
