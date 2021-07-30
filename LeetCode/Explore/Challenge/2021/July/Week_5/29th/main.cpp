#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    const int INF = (int)(1e9);
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat.front().size();
        vector<vector<int>> res(n, vector<int>(m, INF));
        queue<int> que;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (mat[i][j] == 0) {
            que.push(i*m+j);
            res[i][j] = 0;
        }
        while (!que.empty()) {
            int v = que.front(); que.pop();
            int y = v / m, x = v % m, d = res[y][x], nd = d + 1;
            vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            for (int i2=0; i2<4; ++i2) {
                int ny = y + dy[i2], nx = x + dx[i2];
                if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
                if (res[ny][nx] <= nd) continue;
                que.push(ny*m+nx);
                res[ny][nx] = nd;
            }
        }
        return res;
    }
};
