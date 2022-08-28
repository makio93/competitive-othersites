// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        int n = rowConditions.size(), m = colConditions.size();
        vector<vector<int>> rg(k), cg(k);
        vector<int> rdeg(k), cdeg(k);
        for (int i=0; i<n; ++i) {
            rg[rowConditions[i][0]-1].push_back(rowConditions[i][1]-1);
            rdeg[rowConditions[i][1]-1]++;
        }
        for (int i=0; i<m; ++i) {
            cg[colConditions[i][0]-1].push_back(colConditions[i][1]-1);
            cdeg[colConditions[i][1]-1]++;
        }
        queue<int> que;
        vector<int> rlst, clst;
        for (int i=0; i<k; ++i) if (rdeg[i] == 0) que.push(i);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            rlst.push_back(vi);
            for (int ti : rg[vi]) {
                rdeg[ti]--;
                if (rdeg[ti] == 0) que.push(ti);
            }
        }
        for (int i=0; i<k; ++i) if (cdeg[i] == 0) que.push(i);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            clst.push_back(vi);
            for (int ti : cg[vi]) {
                cdeg[ti]--;
                if (cdeg[ti] == 0) que.push(ti);
            }
        }
        vector<vector<int>> res;
        if ((int)(rlst.size())!=k || (int)(clst.size())!=k) return res;
        vector<int> cids(k, -1);
        for (int i=0; i<k; ++i) cids[clst[i]] = i;
        res.assign(k, vector<int>(k, 0));
        for (int i=0; i<k; ++i) res[i][cids[rlst[i]]] = rlst[i] + 1;
        return res;
    }
};
