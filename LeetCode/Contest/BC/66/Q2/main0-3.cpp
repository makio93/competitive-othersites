#include <bits/stdc++.h>
using namespace std;

// 終了後,自力WA

const int INF = (int)(1e9);
class Solution {
public:
    int minimumBuckets(string street) {
        int n = street.length();
        vector<pair<char, int>> runs;
        runs.emplace_back(street[0], 1);
        for (int i=1; i<n; ++i) {
            if (street[i] == runs.back().first) runs.back().second++;
            else runs.emplace_back(street[i], 1);
        }
        int mval = 0, m = runs.size();
        for (int i=0; i<m; ++i) if (runs[i].first == 'H') mval = max(mval, runs[i].second);
        if (mval >= 3) return -1;
        if (m == 1) {
            if (runs[0].first == 'H') return -1;
            else return 0;
        }
        if (runs[0].first=='H' && runs[0].second>=2) return -1;
        if (runs[m-1].first=='H' && runs[m-1].second>=2) return -1;
        vector<vector<int>> dp(n+2, vector<int>(2, INF));
        dp[0][0] = 0;
        for (int i=0; i<n; ++i) {
            if (street[i] == 'H') dp[i+1][0] = min(dp[i][0], dp[i][1]);
            else {
                if (i-1>=0 && street[i-1]=='H') {
                    dp[i+1][0] = min(dp[i+1][0], dp[i-1][1]);
                    dp[i+1][1] = min(dp[i+1][1], dp[i][0]+1);
                }
                else {
                    dp[i+1][0] = min(dp[i][0], dp[i][1]);
                    dp[i+1][1] = min({dp[i+1][1], dp[i][0]+1, dp[i][1]+1});
                }
            }
        }
        if (street[n-1] == 'H') dp[n+1][0] = min(dp[n+1][0], dp[n-1][1]);
        else dp[n+1][0] = min({dp[n+1][0], dp[n][0], dp[n][1]});
        return dp[n+1][0];
    }
};
