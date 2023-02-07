// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
        dp[0][0] = 0;
        for (int i=0; i<m; ++i) {
            vector<vector<int>> ndp(n+1, vector<int>(m+1, INF));
            for (int j1=0; j1<=n; ++j1) for (int j2=0; j2<=m; ++j2) if (dp[j1][j2] != INF) {
                if (houses[i] == 0) {
                    for (int k=1; k<=n; ++k) {
                        if (j1 == k) ndp[k][j2] = min(ndp[k][j2], dp[j1][j2]+cost[i][k-1]);
                        else ndp[k][j2+1] = min(ndp[k][j2+1], dp[j1][j2]+cost[i][k-1]);
                    }
                }
                else {
                    if (j1 == houses[i]) ndp[houses[i]][j2] = min(ndp[houses[i]][j2], dp[j1][j2]);
                    else ndp[houses[i]][j2+1] = min(ndp[houses[i]][j2+1], dp[j1][j2]);
                }
            }
            swap(ndp, dp);
        }
        int res = INF;
        for (int i=1; i<=n; ++i) res = min(res, dp[i][target]);
        return (res == INF) ? -1 : res;
    }
};
