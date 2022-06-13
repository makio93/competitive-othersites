// 計算量削減版

#include <bits/stdc++.h>
using namespace std;

static vector<int> dp(200);
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp[0] = triangle[0][0];
        for (int i=1; i<n; ++i) {
            dp[i] = dp[i-1] + triangle[i][i];
            for (int j=i-1; j>0; --j) dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
            dp[0] = dp[0] + triangle[i][0];
        }
        int res = (int)(1e9);
        for (int i=0; i<n; ++i) res = min(res, dp[i]);
        return res;
    }
};
