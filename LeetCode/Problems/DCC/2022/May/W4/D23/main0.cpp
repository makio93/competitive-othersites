// 自力AC

#include <bits/stdc++.h>
using namespace std;

const string tar = "01";
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int nlen = strs.size();
        vector<vector<int>> ccnt(nlen, vector<int>(2));
        for (int i=0; i<nlen; ++i) for (char ci : strs[i]) ccnt[i][tar.find(ci)]++;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        dp[0][0] = 0;
        for (int i1=0; i1<nlen; ++i1) {
            vector<vector<int>> ndp(m+1, vector<int>(n+1, -1));
            for (int i=0; i<=m; ++i) for (int j=0; j<=n; ++j) if (dp[i][j] != -1) {
                ndp[i][j] = max(ndp[i][j], dp[i][j]);
                if (i+ccnt[i1][0]<=m && j+ccnt[i1][1]<=n) ndp[i+ccnt[i1][0]][j+ccnt[i1][1]] = max(ndp[i+ccnt[i1][0]][j+ccnt[i1][1]], dp[i][j]+1);
            }
            swap(dp, ndp);
        }
        int res = 0;
        for (int i=0; i<=m; ++i) for (int j=0; j<=n; ++j) if (dp[i][j] != -1) res = max(res, dp[i][j]);
        return res;
    }
};
