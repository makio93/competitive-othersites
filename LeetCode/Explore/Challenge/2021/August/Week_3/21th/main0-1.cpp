#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        auto origin = board;
        auto check = [&](int y, int x) -> bool {
            vector<bool> cnt(10);
            for (int i=0; i<9; ++i) if (board[y][i] != '.') {
                if (cnt[board[y][i]-'0']) return false;
                cnt[board[y][i]-'0'] = true;
            }
            cnt = vector<bool>(10);
            for (int i=0; i<9; ++i) if (board[i][x] != '.') {
                if (cnt[board[i][x]-'0']) return false;
                cnt[board[i][x]-'0'] = true;
            }
            cnt = vector<bool>(10);
            for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) {
                int i2 = y / 3 * 3 + i, j2 = x / 3 * 3 + j;
                if (board[i2][j2] != '.') {
                    if (cnt[board[i2][j2]-'0']) return false;
                    cnt[board[i2][j2]-'0'] = true;
                }
            }
            return true;
        };
        function<bool(int,int)> dfs = [&](int y, int x) {
            if (y==9 && x==0) return true;
            int nid = y * 9 + x + 1, ny = nid / 9, nx = nid % 9;
            if (isdigit(origin[y][x])) {
                if (check(y, x)) return dfs(ny, nx);
                else return false;
            }
            else {
                for (int v=1; v<=9; ++v) {
                    board[y][x] = (char)('0'+v);
                    if (check(y, x) && dfs(ny, nx)) return true;
                }
                board[y][x] = '.';
                return false;
            }
        };
        dfs(0, 0);
    }
};
