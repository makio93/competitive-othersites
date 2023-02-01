#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<pair<int, int>> checks(n);
        for (int i=0; i<n; ++i) checks[i] = { tasks[i][0], i };
        sort(checks.begin(), checks.end());
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        long long t = (long long)checks.front().first;
        int id = 0;
        while (id<n && t>=(long long)checks[id].first) {
            que.emplace(tasks[checks[id].second][1], checks[id].second);
            ++id;
        }
        while (!que.empty() || id<n) {
            auto [ti, idi] = que.top(); que.pop();
            ans.push_back(idi);
            t += (long long)ti;
            if (que.empty() && id<n && t<(long long)checks[id].first) t = (long long)checks[id].first;
            while (id<n && t>=(long long)checks[id].first) {
                que.emplace(tasks[checks[id].second][1], checks[id].second);
                ++id;
            }
        }
        return ans;
    }
};
