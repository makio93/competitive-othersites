// 計算量削減版

#include <bits/stdc++.h>
using namespace std;

static vector<int> dp(200);
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        copy(triangle.back().begin(), triangle.back().end(), dp.begin());
        for (int i=n-2; i>=0; --i) for (int j=0; j<=i; ++j) dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
        return dp[0];
    }
};
