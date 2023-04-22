// 自力AC2(メモリ削減)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(2, vector<int>(n+2));
        int res = n-1;
        for (int i=1; i<=n; ++i) {
            for (int j=n; j>i; --j) dp[i%2][j] = max({ dp[(i-1)%2][j], dp[i%2][j+1], dp[(i-1)%2][j+1]+(s[i-1]==s[j-1]?1:0) });
            res = min(res, n-dp[i%2][i+1]*2);
            if (i+2 <= n+1) res = min(res, n-dp[i%2][i+2]*2-1);
        }
        return res;
    }
};
