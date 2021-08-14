#include <bits/stdc++.h>
using namespace std;

// 自力解答2,WA

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
            int r = l + k;
            unordered_map<int, int> vcnt;
            for (int i=l; i<r; ++i) vcnt[run[i].first] += run[i].second;
            vector<pair<int, int>> pval;
            for (auto p : vcnt) pval.emplace_back(p.second, p.first);
            sort(pval.rbegin(), pval.rend());
            int plen = pval.size();
            for (int i1=0; i1<plen; ++i1) {
                if (i1>=2 && pval[i1].first!=pval[0].first) break;
                int ival = pval[i1].first * pval[i1].first, pid = -1;
                for (int i=l; i<=r; ++i) {
                    if (i==r || run[i].first==pval[i1].second) {
                        if (pid != -1) ival += dp[pid][i];
                        pid = -1;
                    }
                    else { if (pid == -1) pid = i; }
                }
                dp[l][r] = max(dp[l][r], ival);
            }
        }
        return dp[0][m];
    }
};
