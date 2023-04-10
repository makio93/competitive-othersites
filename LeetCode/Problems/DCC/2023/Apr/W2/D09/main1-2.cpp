// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
    string colors;
    vector<vector<int>> g, ccnt;
    vector<bool> visited, searching;
    bool dfs(int vi) {
        if (searching[vi]) return false;
        if (visited[vi]) return true;
        visited[vi] = searching[vi] = true;
        for (const int& ti : g[vi]) {
            if (!dfs(ti)) return false;
            for (int i=0; i<26; ++i) ccnt[vi][i] = max(ccnt[vi][i], ccnt[ti][i]);
        }
        ccnt[vi][colors[vi]-'a']++;
        searching[vi] = false;
        return true;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length(), m = edges.size();
        this->colors = colors;
        g.assign(n, vector(0, -1));
        for (int i=0; i<m; ++i) g[edges[i][0]].push_back(edges[i][1]);
        ccnt.assign(n, vector(26, 0));
        visited.assign(n, false);
        searching.assign(n, false);
        int res = 0;
        for (int i=0; i<n; ++i) {
            if (!dfs(i)) return -1;
            res = max(res, *max_element(ccnt[i].begin(), ccnt[i].end()));
        }
        return res;
    }
};
