// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int INF = (int)(1e9);
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(target+1, vector<int>(n, INF)));
        if (houses[0] == 0) for (int i=0; i<n; ++i) dp[0][1][i] = cost[0][i];
        else dp[0][1][houses[0]-1] = 0;
        for (int i=1; i<m; ++i) {
            for (int j=1; j<=min(target, i+1); ++j) for (int k=0; k<n; ++k) {
                if (houses[i]!=0 && houses[i]!=k+1) continue;
                int pval = INF;
                for (int k2=0; k2<n; ++k2) {
                    if (k2 == k) pval = min(pval, dp[i-1][j][k2]);
                    else pval = min(pval, dp[i-1][j-1][k2]);
                }
                dp[i][j][k] = pval + (houses[i] == 0 ? cost[i][k] : 0);
            }
        }
        int res = INF;
        for (int i=0; i<n; ++i) res = min(res, dp[m-1][target][i]);
        return res == INF ? -1 : res;
    }
};
