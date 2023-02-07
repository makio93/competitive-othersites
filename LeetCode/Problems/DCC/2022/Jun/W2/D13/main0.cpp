// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        dp[0] = triangle[0][0];
        for (int i=1; i<n; ++i) for (int j=i; j>=0; --j) {
            if (j == i) dp[j] = dp[j-1] + triangle[i][j];
            else if (j == 0) dp[j] = dp[j] + triangle[i][j];
            else dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
        }
        int res = INF;
        for (int i=0; i<n; ++i) res = min(res, dp[i]);
        return res;
    }
};
