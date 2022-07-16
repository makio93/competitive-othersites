// 解説AC1

#include <bits/stdc++.h>
using namespace std;

const int mod = (int)(1e9) + 7;
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        auto dfs = [&](auto dfs, int ri, int ci, int si) -> int {
            if (ri<0 || ri>=m || ci<0 || ci>=n) return 1;
            if (memo[ri][ci][si] != -1) return memo[ri][ci][si];
            if (si == 0) return memo[ri][ci][si] = 0;
            return memo[ri][ci][si] = ((dfs(dfs, ri-1, ci, si-1) + dfs(dfs, ri, ci+1, si-1)) % mod +
                (dfs(dfs, ri+1, ci, si-1) + dfs(dfs, ri, ci-1, si-1)) % mod) % mod;
        };
        return dfs(dfs, startRow, startColumn, maxMove);
    }
};
