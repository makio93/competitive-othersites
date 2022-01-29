#include <bits/stdc++.h>
using namespace std;

// 自力AC

const int INF = (int)(1e9);
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        vector<pair<int, int>> lds(n);
        for (int i=0; i<n; ++i) lds[i] = { courses[i][1], courses[i][0] };
        sort(lds.begin(), lds.end());
        vector<int> dp(n+1, INF);
        dp[0] = 0;
        for (int i=0; i<n; ++i) {
            int di = upper_bound(dp.begin(), dp.end(), lds[i].first-lds[i].second) - dp.begin();
            for (int j=di; j-1>=0; --j) {
                if (dp[j] <= dp[j-1]+lds[i].second) break;
                dp[j] = min(dp[j], dp[j-1]+lds[i].second);
            }
        }
        int res = 0;
        for (int i=0; i<=n; ++i) if (dp[i] != INF) res = max(res, i);
        return res;
    }
};
