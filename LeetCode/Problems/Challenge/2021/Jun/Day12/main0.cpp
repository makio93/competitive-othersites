#include <bits/stdc++.h>
using namespace std;

// 自力TLE

using ll = long long;
const int INF = (int)(1.1e9);
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<map<int, int>> dp(n+1);
        dp[0][0] = startFuel;
        for (int i=1; i<=n; ++i) for (int j=0; j<i; ++j) {
            int dist = ((j==0) ? stations[i-1][0] : (stations[i-1][0]-stations[j-1][0]));
            auto pitr = dp[j].begin();
            while (pitr != dp[j].end()) {
                bool br = (next(pitr)!=dp[j].end() && next(pitr)->second<=pitr->second);
                if (pitr->second >= dist) {
                    if (dp[i].find(pitr->first+1) == dp[i].end()) dp[i][pitr->first+1] = min(INF, pitr->second-dist+stations[i-1][1]);
                    else dp[i][pitr->first+1] = max(dp[i][pitr->first+1], min(INF, pitr->second-dist+stations[i-1][1]));
                    ++pitr;
                }
                else pitr = dp[j].erase(pitr);
                if (br) pitr = dp[j].erase(pitr, dp[j].end());
            }
        }
        int res = INF;
        for (int i=0; i<=n; ++i) for (auto pi : dp[i]) {
            if (res!=INF && pi.first>=res) break;
            int dist = ((i==0) ? target : (target-stations[i-1][0]));
            if (pi.second >= dist) res = min(res, pi.first);
        }
        if (res == INF) res = -1;
        return res;
    }
};
