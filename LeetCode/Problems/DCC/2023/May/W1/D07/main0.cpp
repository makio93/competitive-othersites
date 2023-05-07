// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> res(n), dp(n, INF);
        for (int i=0; i<n; ++i) {
            int id = upper_bound(dp.begin(), dp.end(), obstacles[i]) - dp.begin();
            dp[id] = obstacles[i];
            res[i] = id + 1;
        }
        return res;
    }
};
