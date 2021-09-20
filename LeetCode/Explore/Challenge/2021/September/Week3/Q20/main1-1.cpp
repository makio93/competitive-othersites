#include <bits/stdc++.h>
using namespace std;

// 解説AC1

class Solution {
private:
    int n = 3;
    vector<vector<int>> board;
    bool checkRow(int ri) {
        for (int i=1; i<n; ++i) if (board[ri][i] != board[ri][0]) return false;
        return true;
    }
    bool checkCol(int ci) {
        for (int i=1; i<n; ++i) if (board[i][ci] != board[0][ci]) return false;
        return true;
    }
    bool checkDia1() {
        for (int i=1; i<n; ++i) if (board[i][i] != board[0][0]) return false;
        return true;
    }
    bool checkDia2() {
        for (int i=1; i<n; ++i) if (board[i][n-i-1] != board[0][n-1]) return false;
        return true;
    }
public:
    string tictactoe(vector<vector<int>>& moves) {
        board.assign(n, vector<int>(n));
        int pnum = 1;
        for (auto mi : moves) {
            board[mi[0]][mi[1]] = pnum;
            if (checkRow(mi[0]) || checkCol(mi[1]) || (mi[0]==mi[1]&&checkDia1()) || (mi[0]+mi[1]==n-1&&checkDia2())) {
                return (pnum==1) ? "A" : "B";
            }
            pnum *= -1;
        }
        return (moves.size()<n*n) ? "Pending" : "Draw";
    }
};
