// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size(), m = edges.size();
        vector<vector<int>> slsts(n);
        vector<unordered_set<int>> tos(n);
        for (int i=0; i<m; ++i) {
            if (tos[edges[i][0]].find(edges[i][1]) == tos[edges[i][0]].end()) {
                tos[edges[i][0]].insert(edges[i][1]);
                if (vals[edges[i][1]] > 0) slsts[edges[i][0]].push_back(vals[edges[i][1]]);
            }
            if (tos[edges[i][1]].find(edges[i][0]) == tos[edges[i][1]].end()) {
                tos[edges[i][1]].insert(edges[i][0]);
                if (vals[edges[i][0]] > 0) slsts[edges[i][1]].push_back(vals[edges[i][0]]);
            }
        }
        int res = -INF;
        for (int i=0; i<n; ++i) {
            sort(slsts[i].rbegin(), slsts[i].rend());
            int val = vals[i], len = slsts[i].size();
            for (int j=0; j<min(k,len); ++j) val += slsts[i][j];
            res = max(res, val);
        }
        return res;
    }
};
