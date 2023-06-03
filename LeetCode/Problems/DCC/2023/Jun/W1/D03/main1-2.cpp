// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> g(n);
        for (int i=0; i<n; ++i) if (manager[i] != -1) g[manager[i]].push_back(i);
        queue<pair<int, int>> que;
        int res = 0;
        que.emplace(headID, 0);
        while (!que.empty()) {
            auto [vi, di] = que.front(); que.pop();
            res = max(res, di);
            for (const int& ti : g[vi]) que.emplace(ti, di+informTime[vi]);
        }
        return res;
    }
};
