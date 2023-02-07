#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board.front().size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (board[i][j]=='O' && !visited[i][j]) {
            queue<pair<int, int>> que;
            set<pair<int, int>> prod;
            visited[i][j] = true;
            bool sur = true;
            prod.emplace(i, j);
            que.emplace(i, j);
            while (!que.empty()) {
                auto [y, x] = que.front(); que.pop();
                for (int i2=0; i2<4; ++i2) {
                    int ny = y + dy[i2], nx = x + dx[i2];
                    if (ny<0 || ny>=m || nx<0 || nx>=n) {
                        sur = false;
                        continue;
                    }
                    if (board[ny][nx]!='O' || visited[ny][nx]) continue;
                    visited[ny][nx] = true;
                    prod.emplace(ny, nx);
                    que.emplace(ny, nx);
                }
            }
            if (sur) for (auto pi : prod) board[pi.first][pi.second] = 'X';
        }
    }
};