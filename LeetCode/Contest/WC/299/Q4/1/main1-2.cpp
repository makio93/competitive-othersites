// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
    vector<int> nums;
    vector<unordered_set<int>> g;
    vector<bool> visited;
    int dfs0(int vi=0) {
        visited[vi] = true;
        int res = nums[vi];
        for (const int& ti : g[vi]) if (!visited[ti]) res ^= dfs0(ti);
        return res;
    }
    int mval;
    int dfs1(int vi, int val0, int aval) {
        visited[vi] = true;
        int res = nums[vi];
        for (const int& ti : g[vi]) if (!visited[ti]) {
            int val1 = dfs1(ti, val0, aval), val2 = aval ^ val1;
            mval = min(mval, max({val0,val1,val2})-min({val0,val1,val2}));
            res ^= val1;
        }
        return res;
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        this->nums = nums;
        g.assign(n, unordered_set<int>());
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].insert(edges[i][1]);
            g[edges[i][1]].insert(edges[i][0]);
        }
        int sval = 0;
        for (int i=0; i<n; ++i) sval ^= nums[i];
        mval = INF;
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].erase(edges[i][1]);
            g[edges[i][1]].erase(edges[i][0]);
            visited.assign(n, false);
            int val0 = dfs0(), sid = -1;
            for (int i=0; i<n; ++i) if (!visited[i]) {
                sid = i;
                break;
            }
            dfs1(sid, val0, sval^val0);
            visited.assign(n, false);
            dfs1(0, sval^val0, val0);
            g[edges[i][0]].insert(edges[i][1]);
            g[edges[i][1]].insert(edges[i][0]);
        }
        return mval;
    }
};
