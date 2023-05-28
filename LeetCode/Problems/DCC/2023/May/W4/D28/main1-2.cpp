// 解説AC2

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, INF));
        for (int k=0; k<m; ++k) for (int i=0,j=i+k; i<m&&j<m; ++i,++j) {
            if (k <= 1) dp[i][j] = 0;
            else if (k == 2) dp[i][j] = cuts[j] - cuts[i];
            else {
                int tval = INF;
                for (int i2=i+1; i2<j; ++i2) tval = min(tval, dp[i][i2]+dp[i2][j]);
                dp[i][j] = tval + cuts[j] - cuts[i];
            }
        }
        return dp[0][m-1];
    }
};
