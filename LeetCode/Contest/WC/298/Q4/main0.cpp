// 終了後,自力,WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        int len = prices.size();
        vector<vector<ll>> dp(m+1, vector<ll>(n+1, 0));
        for (int i1=0; i1<len; ++i1) {
            for (int i=0; i+prices[i1][0]<=m; ++i) for (int j=prices[i1][1]; j<=n; ++j) {
                dp[i+prices[i1][0]][j] = max(dp[i+prices[i1][0]][j], dp[i][j]+prices[i1][2]);
            }
            for (int i=prices[i1][0]; i<=m; ++i) for (int j=0; j+prices[i1][1]<=n; ++j) {
                dp[i][j+prices[i1][1]] = max(dp[i][j+prices[i1][1]], dp[i][j]+prices[i1][2]);
            }
        }
        ll res = 0;
        for (int i=0; i<=m; ++i) for (int j=0; j<=n; ++j) res = max(res, dp[i][j]);
        return res;
    }
};
