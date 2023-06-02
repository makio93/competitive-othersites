// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dists(n, vector<int>(n, -1));
        queue<pair<int, int>> que;
        if (grid[0][0] == 0) {
            que.emplace(0, 0);
            dists[0][0] = 1;
        }
        while (!que.empty()) {
            auto [yi, xi] = que.front(); que.pop();
            int di = dists[yi][xi], ndi = di + 1;
            for (int nyi=yi-1; nyi<=yi+1; ++nyi) for (int nxi=xi-1; nxi<=xi+1; ++nxi) 
                if (nyi>=0 && nyi<n && nxi>=0 && nxi<n && grid[nyi][nxi]==0 && dists[nyi][nxi]==-1) {
                    que.emplace(nyi, nxi);
                    dists[nyi][nxi] = ndi;
            }
        }
        return dists[n-1][n-1];
    }
};
