// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+2, vector<int>(n+2));
        for (int i=1; i<=n; ++i) for (int j=n; j>i; --j) {
            dp[i][j] = max({ dp[i-1][j], dp[i][j+1], dp[i-1][j+1]+(s[i-1]==s[j-1]?1:0) });
        }
        int res = n;
        for (int i=0; i<=n; ++i) {
            res = min(res, n-dp[i][i+1]*2);
            if (i+2 <= n+1) res = min(res, (n-1)-dp[i][i+2]*2);
        }
        return res;
    }
};
