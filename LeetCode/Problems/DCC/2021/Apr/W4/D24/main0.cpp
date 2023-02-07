#include <bits/stdc++.h>
using namespace std;

// 自力WA

class Solution {
    vector<vector<int>> g;
    vector<int> dist;
    set<pair<int, int>> rlst;
    void dfs(unordered_set<int>& tlst, int vi, int pi=-1) {
        if (dist[vi] == 1) return;
        if (dist[vi] == 0) {
            dist[vi] = 1;
            tlst.insert(vi);
        }
        else if (dist[vi] == -1) {
            dist[vi] = 0;
            for (int ti : g[vi]) if (ti != pi) {
                unordered_set<int> ntlst;
                dfs(ntlst, ti, vi);
                if (!ntlst.empty()) {
                    int ai = vi, bi = ti;
                    if (ai > bi) swap(ai, bi);
                    rlst.emplace(ai, bi);
                    for (int nvi : ntlst) tlst.insert(nvi);
                }
            }
            if (tlst.find(vi) != tlst.end()) tlst.erase(vi);
            if (!tlst.empty()) dist[vi] = 1;
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        g = vector<vector<int>>(n);
        for (int i=0; i<m; ++i) {
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }
        dist = vector<int>(n, -1);
        unordered_set<int> tlst;
        dfs(tlst, 0);
        vector<vector<int>> res;
        for (int i=0; i<m; ++i) {
            int ai = connections[i][0], bi = connections[i][1];
            if (ai > bi) swap(ai, bi);
            if (rlst.find({ ai, bi }) == rlst.end()) res.push_back(vector<int>({ ai, bi }));
        }
        return res;
    }
};
