// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int INF = (int)(1e9);
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(target+1, vector<int>(n+1, -1)));
        auto dfs = [&](auto dfs, int di=0, int ri=0, int pi=0) -> int {
            if (ri > target) return INF;
            if (di == m) return (ri == target ? 0 : INF);
            if (memo[di][ri][pi] != -1) return memo[di][ri][pi];
            int rval = INF;
            if (houses[di] == 0) {
                for (int ci=1; ci<=n; ++ci) {
                    int nri = ri + (pi != ci);
                    rval = min(rval, cost[di][ci-1]+dfs(dfs,di+1,nri,ci));
                }
            }
            else {
                int nri = ri + (pi != houses[di]);
                rval = dfs(dfs, di+1, nri, houses[di]);
            }
            return memo[di][ri][pi] = rval;
        };
        int res = dfs(dfs);
        return res == INF ? -1 : res;
    }
};
