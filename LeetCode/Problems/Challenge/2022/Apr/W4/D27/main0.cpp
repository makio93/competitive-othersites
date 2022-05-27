// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<vector<int>> g(n);
        for (auto vi : pairs) {
            g[vi[0]].push_back(vi[1]);
            g[vi[1]].push_back(vi[0]);
        }
        vector<int> gid(n, -1);
        auto dfs = [&](auto dfs, int vi, int gi) -> void {
            gid[vi] = gi;
            for (int ti : g[vi]) if (gid[ti] == -1) dfs(dfs, ti, gi);
        };
        int gval = 0;
        for (int i=0; i<n; ++i) if (gid[i] == -1) {
            dfs(dfs, i, gval);
            ++gval;
        }
        vector<vector<int>> ilst(gval);
        for (int i=0; i<n; ++i) ilst[gid[i]].push_back(i);
        for (int i=0; i<gval; ++i) {
            string tmp;
            for (int id : ilst[i]) tmp.push_back(s[id]);
            sort(tmp.begin(), tmp.end());
            for (int j=0; j<(int)(tmp.length()); ++j) s[ilst[i][j]] = tmp[j];
        }
        return s;
    }
};
