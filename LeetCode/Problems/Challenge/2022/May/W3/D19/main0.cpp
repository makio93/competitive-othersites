// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.front().size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        auto dfs = [&](auto dfs, int yi, int xi) -> int {
            if (dp[yi][xi] != -1) return dp[yi][xi];
            int mval = 0;
            for (int i1=0; i1<4; ++i1) {
                int ny = yi + dy[i1], nx = xi + dx[i1];
                if (ny<0 || ny>=m || nx<0 || nx>=n || matrix[ny][nx]<=matrix[yi][xi]) continue;
                mval = max(mval, dfs(dfs, ny, nx)); 
            }
            return dp[yi][xi] = mval + 1;
        };
        int res = 0;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) res = max(res, dfs(dfs, i, j));
        return res;
    }
};
