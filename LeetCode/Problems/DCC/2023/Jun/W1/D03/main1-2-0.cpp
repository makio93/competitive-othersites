// 解説AC2-0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> g(n);
        for (int i=0; i<n; ++i) if (manager[i] != -1) g[manager[i]].push_back(i);
        queue<int> que;
        vector<int> dist(n);
        que.emplace(headID);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            for (const int& ti : g[vi]) {
                dist[ti] = dist[vi] + informTime[vi];
                que.push(ti);
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
};
