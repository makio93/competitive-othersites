#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i=0; i<n; ++i) jobs[i] = { endTime[i], startTime[i], profit[i] };
        sort(jobs.begin(), jobs.end());
        map<int, int> schedules;
        for (int i=0; i<n; ++i) schedules[jobs[i][0]] = max(schedules[jobs[i][0]], i);
        vector<int> dp(n+1);
        for (int i=0; i<n; ++i) {
            auto itr = schedules.upper_bound(jobs[i][1]);
            int pid = 0;
            if (itr != schedules.begin()) pid = prev(itr)->second + 1;
            dp[i+1] = max({dp[i+1], dp[pid]+jobs[i][2], dp[i]});
        }
        return dp[n];
    }
};
