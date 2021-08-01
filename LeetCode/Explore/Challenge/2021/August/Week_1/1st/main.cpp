#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> board(n, vector<int>(n, -1));
        vector<int> gsize;
        int gid = 0, res = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (grid[i][j]==1 && board[i][j]==-1) {
            int cnt = 0;
            queue<pair<int, int>> que;
            que.emplace(i, j);
            ++cnt;
            board[i][j] = gid;
            while (!que.empty()) {
                auto [y, x] = que.front(); que.pop();
                for (int i2=0; i2<4; ++i2) {
                    int ny = y + dy[i2], nx = x + dx[i2];
                    if (ny<0 || ny>=n || nx<0 || nx>=n) continue;
                    if (grid[ny][nx] != 1) continue;
                    if (board[ny][nx] != -1) continue;
                    que.emplace(ny, nx);
                    ++cnt;
                    board[ny][nx] = gid;
                }
            }
            gsize.push_back(cnt);
            res = max(res, cnt);
            ++gid;
        }
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (grid[i][j] == 0) {
            set<int> gids;
            for (int i2=0; i2<4; ++i2) {
                int ny = i + dy[i2], nx = j + dx[i2];
                if (ny<0 || ny>=n || nx<0 || nx>=n) continue;
                if (grid[ny][nx] == 1) gids.insert(board[ny][nx]);
            }
            int sval = 1;
            for (int gi : gids) sval += gsize[gi];
            res = max(res, sval);
        }
        return res;
    }
};
