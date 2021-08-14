#include <bits/stdc++.h>
using namespace std;

// 自力解答1,WA

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<pair<int, int>> run;
        run.emplace_back(boxes.front(), 1);
        for (int i=1; i<n; ++i) {
            if (boxes[i] == run.back().first) run.back().second++;
            else run.emplace_back(boxes[i], 1);
        }
        int m = run.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1));
        for (int l=0; l<m; ++l) dp[l][l+1] = run[l].second * run[l].second;
        for (int k=2; k<=m; ++k) for (int l=0; l+k<=m; ++l) {
            int r = l + k, lcnt = run[l].second, rcnt = run[r-1].second;
            for (int i=l+1; i<r; ++i) if (run[i].first == run[l].first) lcnt += run[i].second;
            for (int i=l; i<r-1; ++i) if (run[i].first == run[r-1].first) rcnt += run[i].second;
            int lval = lcnt * lcnt, rval = rcnt * rcnt, pid = -1;
            for (int i=l+1; i<=r; ++i) {
                if (i==r || run[i].first==run[l].first) {
                    if (pid != -1) lval += dp[pid][i];
                    pid = -1;
                }
                else { if (pid == -1) pid = i; }
            }
            pid = -1;
            for (int i=l; i<=r-1; ++i) {
                if (i==r-1 || run[i].first==run[r-1].first) {
                    if (pid != -1) rval += dp[pid][i];
                    pid = -1;
                }
                else { if (pid == -1) pid = i; }
            }
            dp[l][r] = max({ dp[l][r-1]+run[r-1].second*run[r-1].second, dp[l+1][r]+run[l].second*run[l].second, lval, rval });
        }
        return dp[0][m];
    }
};
