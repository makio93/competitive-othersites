#include <bits/stdc++.h>
using namespace std;

// 終了後,自力AC1

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<int>> sum(m+1, vector<int>(n+1)), stamps(m+1, vector<int>(n+1));
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + grid[i][j];
        for (int i=0; i+stampHeight<=m; ++i) for (int j=0; j+stampWidth<=n; ++j) {
            if (sum[i+stampHeight][j+stampWidth]-sum[i+stampHeight][j]-sum[i][j+stampWidth]+sum[i][j] == 0) {
                stamps[i][j]++; stamps[i+stampHeight][j]--;
                stamps[i][j+stampWidth]--; stamps[i+stampHeight][j+stampWidth]++;
            }
        }
        for (int i=0; i<=n; ++i) for (int j=0; j<m; ++j) stamps[j+1][i] += stamps[j][i];
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) stamps[i][j+1] += stamps[i][j];
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (grid[i][j]==0 && stamps[i][j]==0) return false;
        return true;
    }
};
