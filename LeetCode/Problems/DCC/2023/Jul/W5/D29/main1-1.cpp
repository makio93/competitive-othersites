// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double soupServings(int n) {
        if (n/25 >= 200) return 1.0;
        int m = (n + 24) / 25;
        vector<vector<double>> dp(m+1, vector<double>(m+1));
        dp[0][0] = 0.5;
        for (int i=1; i<=m; ++i) {
            dp[0][i] = 1.0;
            for (int j=1; j<=m; ++j) for (int j2=1; j2<=4; ++j2) dp[j][i] += dp[max(0, j-j2)][max(0, i-(4-j2))] / 4.0;
        }
        return dp[m][m];
    }
};
