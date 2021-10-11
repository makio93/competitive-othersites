#include <bits/stdc++.h>
using namespace std;

// 解説での解法にて実装,TLE

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board.front().size(), l = word.length();
        function<bool(int,int,int)> dfs = [&](int y, int x, int d) -> bool {
            if (word[d] != board[y][x]) return false;
            else if (d == l-1) return true;
            else {
                char c = board[y][x];
                board[y][x] = '*';
                vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
                bool res = false;
                for (int i1=0; i1<4; ++i1) {
                    int ny = y + dy[i1], nx = x + dx[i1];
                    if (ny<0 || ny>=m || nx<0 || nx>=n || board[ny][nx]=='*') continue;
                    res |= dfs(ny, nx, d+1);
                    if (res) break;
                }
                board[y][x] = c;
                return res;
            }
        };
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (dfs(i, j, 0)) return true;
        return false;
    }
};
