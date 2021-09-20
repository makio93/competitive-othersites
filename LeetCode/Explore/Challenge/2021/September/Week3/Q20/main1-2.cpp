#include <bits/stdc++.h>
using namespace std;

// 解説AC2

class Solution {
    int n = 3;
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rows(3), cols(3);
        int diag1 = 0, diag2 = 0, pnum = 1;
        for (auto mi : moves) {
            rows[mi[0]] += pnum;
            cols[mi[1]] += pnum;
            if (mi[0] == mi[1]) diag1 += pnum;
            if (mi[0]+mi[1] == n-1) diag2 += pnum;
            if (abs(rows[mi[0]])==n || abs(cols[mi[1]])==n || (mi[0]==mi[1]&&abs(diag1)==n) || (mi[0]+mi[1]==n-1&&abs(diag2)==n)) {
                return (pnum==1) ? "A" : "B";
            }
            pnum *= -1;
        }
        return (moves.size()<n*n) ? "Pending" : "Draw";
    }
};
