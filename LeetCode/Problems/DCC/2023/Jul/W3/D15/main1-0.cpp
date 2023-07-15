// 自力AC(ヒント有)

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](auto ai, auto bi) -> bool { return ai[1] < bi[1]; });
        function<int(int)> binary_search = [&](int target) {
            if (target <= events[0][1]) return -1;
            int li = 0, ri = n;
            while (ri-li > 1) {
                int ci = li + (ri-li) / 2;
                if (events[ci][1] < target) li = ci;
                else ri = ci;
            }
            return li;
        };
        vector<vector<int>> dp(n+1, vector<int>(k+1, -INF));
        dp[0].assign(k+1, 0);
        for (int i=0; i<n; ++i) {
            int li = binary_search(events[i][0]);
            for (int j=0; j<=k; ++j) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                if (j-1 >= 0) {
                    dp[i+1][j] = max(dp[i+1][j], dp[i+1][j-1]);
                    if (li >= 0) dp[i+1][j] = max(dp[i+1][j], dp[li+1][j-1]+events[i][2]);
                    else dp[i+1][j] = max(dp[i+1][j], events[i][2]);
                }
            }
        }
        return dp[n][k];
    }
};
