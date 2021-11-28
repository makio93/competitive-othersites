#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    void dfs(vector<vector<int>>& res, vector<int>& path, vector<vector<int>>& graph, int v=0) {
        if (v == (int)(graph.size())-1) {
            res.push_back(path);
            return;
        }
        for (int t : graph[v]) {
            path.push_back(t);
            dfs(res, path, graph, t);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        dfs(res, path, graph);
        return res;
    }
};
