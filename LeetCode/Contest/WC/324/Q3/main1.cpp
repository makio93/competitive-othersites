// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const vector<vector<int>> plst = { { 0, 1, 2, 3 }, { 0, 2, 1, 3 }, { 0, 3, 1, 2 } };
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<unordered_set<int>> g(n);
        for (int i=0; i<m; ++i) {
            int ai = edges[i][0] - 1, bi = edges[i][1] - 1;
            g[ai].insert(bi);
            g[bi].insert(ai);
        }
        vector<int> odds;
        for (int i=0; i<n; ++i) if ((int)(g[i].size())%2 == 1) odds.push_back(i);
        if ((int)(odds.size()) == 0) return true;
        if ((int)(odds.size()) == 2) {
            for (int i=0; i<n; ++i) if (g[odds[0]].find(i)==g[odds[0]].end() && g[odds[1]].find(i)==g[odds[1]].end()) return true;
        }
        if ((int)(odds.size()) == 4) {
            for (const vector<int>& p : plst) 
                if (g[odds[p[0]]].find(odds[p[1]])==g[odds[p[0]]].end() && g[odds[p[2]]].find(odds[p[3]])==g[odds[p[2]]].end()) return true;
        }
        return false;
    }
};
