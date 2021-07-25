#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        map<long long, vector<int>> waiting;
        for (int i=0; i<n; ++i) waiting[tasks[i][0]].push_back(i);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        vector<int> res;
        long long t = 0;
        while (!waiting.empty() || !que.empty()) {
            if (que.empty() && t<waiting.begin()->first) t = waiting.begin()->first;
            auto itr = waiting.upper_bound(t);
            for (auto itr2=waiting.begin(); itr2!=itr; ++itr2) {
                for (int i=0; i<(int)(itr2->second.size()); ++i) que.emplace(tasks[itr2->second[i]][1], itr2->second[i]);
            }
            waiting.erase(waiting.begin(), itr);
            auto p = que.top(); que.pop();
            res.push_back(p.second);
            t += p.first;
        }
        return res;
    }
};
