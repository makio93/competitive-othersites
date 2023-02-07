// 自力AC-2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int nlen = strs.size();
        vector<vector<int>> ccnt(nlen, vector<int>(2));
        for (int i=0; i<nlen; ++i) for (char& ci : strs[i]) {
            if (ci == '0') ccnt[i][0]++;
            else ccnt[i][1]++;
        }
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        dp[0][0] = 0;
        for (int i1=0; i1<nlen; ++i1) {
            for (int i=m-ccnt[i1][0]; i>=0; --i) for (int j=n-ccnt[i1][1]; j>=0; --j) if (dp[i][j] != -1) {
                dp[i+ccnt[i1][0]][j+ccnt[i1][1]] = max(dp[i+ccnt[i1][0]][j+ccnt[i1][1]], dp[i][j]+1);
            }
        }
        int res = 0;
        for (int i=0; i<=m; ++i) for (int j=0; j<=n; ++j) if (dp[i][j] != -1) res = max(res, dp[i][j]);
        return res;
    }
};
