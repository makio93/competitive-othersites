#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        vector<vector<int>> board(3, vector<int>(3, -1));
        for (int i=0; i<n; ++i) board[moves[i][0]][moves[i][1]] = i%2;
        for (int i=0; i<3; ++i) {
            int tval = board[i][0];
            for (int j=1; j<3; ++j) if (tval != board[i][j]) tval = 2;
            if (tval!=2 && tval!=-1) return (string)((tval == 0) ? "A" : "B");
        }
        for (int i=0; i<3; ++i) {
            int tval = board[0][i];
            for (int j=1; j<3; ++j) if (tval != board[j][i]) tval = 2;
            if (tval!=2 && tval!=-1) return (string)((tval == 0) ? "A" : "B");
        }
        {
            int tval = board[0][0];
            for (int i=1; i<3; ++i) if (tval != board[i][i]) tval = 2;
            if (tval!=2 && tval!=-1) return (string)((tval == 0) ? "A" : "B");
        }
        {
            int tval = board[0][2];
            for (int i=1; i<3; ++i) if (tval != board[i][2-i]) tval = 2;
            if (tval!=2 && tval!=-1) return (string)((tval == 0) ? "A" : "B");
        }
        for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) if (board[i][j] == -1) return (string)("Pending");
        return (string)("Draw");
    }
};
