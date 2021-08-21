#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; ++i) {
            vector<int> cnt(9);
            for (int j=0; j<9; ++j) if (isdigit(board[i][j])) cnt[board[i][j]-'1']++;
            for (int j=0; j<9; ++j) if (cnt[j] > 1) return false;
        }
        for (int j=0; j<9; ++j) {
            vector<int> cnt(9);
            for (int i=0; i<9; ++i) if (isdigit(board[i][j])) cnt[board[i][j]-'1']++;
            for (int i=0; i<9; ++i) if (cnt[i] > 1) return false;
        }
        for (int i1=0; i1<9; i1+=3) for (int j1=0; j1<9; j1+=3) {
            vector<int> cnt(9);
            for (int i2=0; i2<3; ++i2) for (int j2=0; j2<3; ++j2) if (isdigit(board[i1+i2][j1+j2])) cnt[board[i1+i2][j1+j2]-'1']++;
            for (int i=0; i<9; ++i) if (cnt[i] > 1) return false;
        }
        return true;
    }
};
