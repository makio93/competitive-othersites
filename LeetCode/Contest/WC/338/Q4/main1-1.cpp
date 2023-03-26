// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<unordered_set<int>> g(n);
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].insert(edges[i][1]);
            g[edges[i][1]].insert(edges[i][0]);
        }
        queue<int> leaf;
        for (int i=0; i<n; ++i) {
            int vi = i;
            while ((int)(g[vi].size())==1 && coins[vi]==0) {
                int ti = *g[vi].begin();
                g[vi].erase(ti);
                g[ti].erase(vi);
                vi = ti;
            }
            if ((int)(g[vi].size()) == 1) leaf.push(vi);
        }
        for (int i=0; i<2; ++i) {
            int qlen = leaf.size();
            for (int j=0; j<qlen; ++j) {
                int vi = leaf.front(); leaf.pop();
                if (g[vi].empty()) continue;
                int ti = *g[vi].begin();
                g[vi].erase(ti);
                g[ti].erase(vi);
                if ((int)(g[ti].size()) == 1) leaf.push(ti);
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) res += g[i].size();
        return res;
    }
};
