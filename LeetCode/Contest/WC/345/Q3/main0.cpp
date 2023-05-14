// 本番AC

#include <bits/stdc++.h>
using namespace std;

const vector<int> dy = { -1, 0, 1 };
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i=0; i<m; ++i) visited[i][0] = true;
        for (int i=0; i<n-1; ++i) for (int j=0; j<m; ++j) if (visited[j][i]) {
            for (int i2=0; i2<3; ++i2) {
                int ny = j + dy[i2], nx = i+1;
                if (ny<0 || ny>=m || grid[ny][nx]<=grid[j][i]) continue;
                visited[ny][nx] = true;
            }
        }
        int res = 0;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (visited[i][j]) res = max(res, j);
        return res;
    }
};
