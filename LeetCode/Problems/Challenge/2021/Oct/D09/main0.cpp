#include <bits/stdc++.h>
using namespace std;

// 自力TLE,1

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board.front().size(), wl = words.size();
        vector<string> res;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i1=0; i1<wl; ++i1) {
            int len = words[i1].length();
            bool ok = false;
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) if (board[i][j] == words[i1].front()) {
                    function<bool(int,int,int)> dfs = [&](int y, int x, int d) -> bool {
                        if (d == len-1) return true;
                        visited[y][x] = true;
                        const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
                        bool resi = false;
                        for (int i2=0; i2<4; ++i2) {
                            int ny = y + dy[i2], nx = x + dx[i2];
                            if (ny<0 || ny>=m || nx<0 || nx>=n) continue;
                            if (board[ny][nx] != words[i1][d+1]) continue;
                            if (visited[ny][nx]) continue;
                            if (dfs(ny, nx, d+1)) resi = true;
                            if (resi) break;
                        }
                        visited[y][x] = false;
                        return resi;
                    };
                    if (dfs(i, j, 0)) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
            if (ok) res.push_back(words[i1]);
        }
        return res;
    }
};
