// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<int> rlst;
        rlst.push_back(0);
        for (int i=0; i<n; ++i) {
            rlst.push_back(events[i][0]);
            rlst.push_back(events[i][1]);
        }
        sort(rlst.begin(), rlst.end());
        rlst.erase(unique(rlst.begin(), rlst.end()), rlst.end());
        int m = rlst.size();
        vector<vector<pair<int, int>>> elst(m);
        for (int i=0; i<n; ++i) {
            int li = lower_bound(rlst.begin(), rlst.end(), events[i][0]) - rlst.begin();
            int ri = lower_bound(rlst.begin(), rlst.end(), events[i][1]) - rlst.begin();
            elst[ri].emplace_back(li, events[i][2]);
        }
        vector<vector<int>> dp(m, vector<int>(k+1, -INF));
        dp[0][0] = 0;
        for (int i=1; i<m; ++i) for (int j=0; j<=k; ++j) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (j-1 >= 0) {
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
                for (const auto [li, vi] : elst[i]) dp[i][j] = max(dp[i][j], dp[li-1][j-1]+vi);
            }
        }
        return dp[m-1][k];
    }
};
