#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
    vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
public:
    bool dfs(vector<vector<char>>& board, int y, int x, string& word, int d=0) {
        if (y<0 || y>=board.size() || x<0 || x>=board.front().size() || word[d]!=board[y][x]) return false;
        else if (d == (int)(word.length()-1)) return true;
        else {
            char c = board[y][x];
            board[y][x] = '*';
            bool res = false;
            for (int i1=0; i1<4; ++i1) {
                res |= dfs(board, y+dy[i1], x+dx[i1], word, d+1);
                if (res) break;
            }
            board[y][x] = c;
            return res;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board.front().size();
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (dfs(board, i, j, word)) return true;
        return false;
    }
};
