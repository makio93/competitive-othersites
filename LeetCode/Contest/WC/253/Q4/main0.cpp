#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
    const int INF = (int)(1e9);
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> dp(n+2, INF), res(n);
        for (int i=0; i<n; ++i) {
            int d = distance(dp.begin(), upper_bound(dp.begin(), dp.end(), obstacles[i]));
            res[i] = d + 1;
            dp[d] = obstacles[i];
        }
        return res;
    }
};
