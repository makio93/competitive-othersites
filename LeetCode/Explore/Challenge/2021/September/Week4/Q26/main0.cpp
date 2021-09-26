#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size(), res = 0;
        vector<vector<int>> rtar(2);
        rtar[0] = board.front(); rtar[1] = rtar[0];
        int bcnt = 0;
        for (int i=0; i<n; ++i) if (rtar[0][i] == 1) ++bcnt;
        if ((n%2==0&&bcnt!=n/2) || (n%2==1&&(bcnt!=n/2&&bcnt!=n/2+1))) return -1;
        for (int i=0; i<n; ++i) rtar[1][i] = 1 - rtar[1][i];
        vector<int> rcnt(2);
        for (int i=0; i<n; ++i) {
            if (board[i] == rtar[0]) rcnt[0]++;
            else if (board[i] == rtar[1]) rcnt[1]++;
            else return -1;
        }
        if ((n%2==0&&rcnt[0]!=rcnt[1]) || (n%2==1&&abs(rcnt[0]-rcnt[1])!=1)) return -1;
        if (n%2 == 1) {
            if (rcnt[1] > rcnt[0]) {
                swap(rtar[1], rtar[0]);
                bcnt = n - bcnt;
            }
        }
        int mcnt = 0;
        for (int i=0; i<n; ++i) if (board[i] != rtar[i%2]) ++mcnt;
        if (n%2 == 0) mcnt = min(mcnt, n-mcnt);
        res += mcnt / 2;
        mcnt = 0;
        int zero = 0;
        if (n%2==1 && bcnt==n/2+1) zero = 1;
        if (n%2 == 0) zero = rtar[0][0];
        for (int i=0; i<n; ++i) if (rtar[i%2][i] != zero) ++mcnt;
        if (n%2 == 0) mcnt = min(mcnt, n-mcnt);
        res += mcnt / 2;
        return res;
    }
};
