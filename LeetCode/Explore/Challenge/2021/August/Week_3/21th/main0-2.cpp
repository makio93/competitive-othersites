#include <bits/stdc++.h>
using namespace std;

// 

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<set<int>>> mvals(9, vector<set<int>>(9));
        set<int> avals;
        for (int i=1; i<=9; ++i) avals.insert(i);
        for (int i=0; i<9; ++i) for (int j=0; j<9; ++j) {
            if (isdigit(board[i][j])) mvals[i][j].insert(board[i][j]-'0');
            else mvals[i][j] = avals;
        }
        queue<int> que;
        for (int i=0; i<9; ++i) for (int j=0; j<9; ++j) if ((int)(mvals[i][j].size()) > 1) que.push(i*9+j);
        while (!que.empty()) {
            int pi = que.front(); que.pop();
            int yi = pi / 9, xi = pi % 9;
            auto ms = mvals[yi][xi];
            auto check = [&](int y, int x, int vi) -> bool {
                set<int> orig = { vi };
                {
                    auto used = orig;
                    for (int i=0; i<9; ++i) if (isdigit(board[y][i])) {
                        if (used.find(board[y][i]-'0') != used.end()) return false;
                        else used.insert(board[y][i]-'0');
                    }
                }
                {
                    auto used = orig;
                    for (int i=0; i<9; ++i) if (isdigit(board[i][x])) {
                        if (used.find(board[i][x]-'0') != used.end()) return false;
                        else used.insert(board[i][x]-'0');
                    }
                }
                {
                    auto used = orig;
                    int y2 = y / 3 * 3, x2 = x / 3 * 3;
                    for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) if (isdigit(board[y2+i][x2+j])) {
                        if (used.find(board[y2+i][x2+j]-'0') != used.end()) return false;
                        else used.insert(board[y2+i][x2+j]-'0');
                    }
                }
                return true;
            };
            set<int> ms2;
            for (int msi : ms) if (check(yi, xi, msi)) ms2.insert(msi);
            if ((int)(ms2.size()) == 1) board[yi][xi] = (char)((*ms2.begin()) + '0');
            else {
                que.push(pi);
                mvals[yi][xi] = ms2;
            }
        }
    }
};
