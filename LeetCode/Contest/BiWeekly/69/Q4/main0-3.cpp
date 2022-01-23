#include <bits/stdc++.h>
using namespace std;

// 終了後,自力AC2

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<int>> sum(m+1, vector<int>(n+1));
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + grid[i][j];
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (grid[i][j] == 0) {
            if ((i+1>=m||grid[i+1][j]==1) && (j+1>=n||grid[i][j+1]==1)) {
                if (i-stampHeight+1<0 || j-stampWidth+1<0 || sum[i+1][j+1]-sum[i-stampHeight+1][j+1]-sum[i+1][j-stampWidth+1]+sum[i-stampHeight+1][j-stampWidth+1]!=0) 
                    return false;
            }
            else if (i+1>=m || grid[i+1][j]==1) {
                if (i-stampHeight+1<0 || sum[i+1][j+1]-sum[i-stampHeight+1][j+1]-sum[i+1][j]+sum[i-stampHeight+1][j]!=0)
                    return false;
            }
            else if (j+1>=n || grid[i][j+1]==1) {
                if (j-stampWidth+1<0 || sum[i+1][j+1]-sum[i+1][j-stampWidth+1]-sum[i][j+1]+sum[i][j-stampWidth+1]!=0)
                    return false;
            }
        }
        return true;
    }
};
