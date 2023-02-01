// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
    vector<int> nums, xvals, search;
    vector<vector<int>> g;
    vector<vector<bool>> cids;
    void dfs(int vi=0, int pi=-1) {
        for (const int& ti : search) cids[ti][vi] = true;
        search.push_back(vi);
        xvals[vi] = nums[vi];
        for (const int& ti : g[vi]) if (ti != pi) {
            dfs(ti, vi);
            xvals[vi] ^= xvals[ti];
        }
        search.pop_back();
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        this->nums = nums;
        g.assign(n, vector<int>());
        cids.assign(n, vector<bool>(n));
        xvals.assign(n, 0);
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        dfs();
        int res = INF;
        for (int i=0; i<n-1; ++i) {
            int ai = cids[edges[i][0]][edges[i][1]] ? edges[i][1] : edges[i][0];
            for (int j=i+1; j<n-1; ++j) {
                int bi = cids[edges[j][0]][edges[j][1]] ? edges[j][1] : edges[j][0], aval = xvals[ai], bval = xvals[bi], cval = xvals[0];
                if (cids[ai][bi]) {
                    cval ^= xvals[ai];
                    aval ^= xvals[bi];
                }
                else if (cids[bi][ai]) {
                    cval ^= xvals[bi];
                    bval ^= xvals[ai];
                }
                else {
                    cval ^= xvals[ai];
                    cval ^= xvals[bi];
                }
                res = min(res, max({ aval, bval, cval }) - min({ aval, bval, cval }));
            }
        }
        return res;
    }
};
