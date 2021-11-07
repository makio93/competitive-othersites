#include <bits/stdc++.h>
using namespace std;

// 本番AC

using ll = long long;
class Solution {
    vector<vector<pair<int, int>>> g;
    vector<int> nvalues;
    ll mval;
    void dfs(int vi, int tval, ll vval, int& mti) {
        if (tval > mti) return;
        vval += nvalues[vi];
        int pvals = nvalues[vi];
        nvalues[vi] = 0;
        if (vi == 0) mval = max(mval, vval);
        for (auto pi : g[vi]) {
            int ti = pi.first, ntval = pi.second;
            dfs(ti, tval+ntval, vval, mti);
        }
        nvalues[vi] = pvals;
        return;
    }
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size(), m = edges.size();
        nvalues = values;
        g = vector<vector<pair<int, int>>>(n);
        for (int i=0; i<m; ++i) {
            g[edges[i][0]].emplace_back(edges[i][1], edges[i][2]);
            g[edges[i][1]].emplace_back(edges[i][0], edges[i][2]);
        }
        mval = 0;
        dfs(0, 0, 0LL, maxTime);
        return mval;
    }
};
