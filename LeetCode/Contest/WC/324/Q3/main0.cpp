// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
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
        if ((int)(odds.size()) > 4) return false;
        if ((int)(odds.size()) == 0) return true;
        if ((int)(odds.size()) == 2) {
            if (g[odds[0]].find(odds[1]) == g[odds[0]].end()) return true;
            else {
                for (int i=0; i<n; ++i) if (i!=odds[0] && g[odds[0]].find(i)==g[odds[0]].end() && g[odds[1]].find(i)==g[odds[1]].end()) return true;
                return false;
            }
        }
        if ((int)(odds.size()) == 4) {
            vector<int> ord(4);
            iota(ord.begin(), ord.end(), 0);
            do {
                if (g[odds[ord[0]]].find(odds[ord[1]])==g[odds[ord[0]]].end() && g[odds[ord[2]]].find(odds[ord[3]])==g[odds[ord[2]]].end()) return true;
            } while (next_permutation(ord.begin(), ord.end()));
            return false;
        }
        return false;
    }
};
