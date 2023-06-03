// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> g(n);
        for (int i=0; i<n; ++i) if (manager[i] != -1) g[manager[i]].push_back(i);
        function<int(int,int)> dfs = [&](int vi, int pi) {
            int rval = 0;
            for (const int& ti : g[vi]) if (ti != pi) rval = max(rval, dfs(ti, vi));
            return rval + informTime[vi];
        };
        return dfs(headID, -1);
    }
};
