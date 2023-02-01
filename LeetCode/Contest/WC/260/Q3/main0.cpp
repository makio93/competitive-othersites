#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board.front().size(), len = word.length();
        bool res = false;
        for (int i=0; i<n; ++i) {
            vector<int> sid;
            sid.push_back(-1);
            for (int j=0; j<m; ++j) if (board[i][j] == '#') sid.push_back(j);
            sid.push_back(m);
            for (int j=0; j+1<(int)(sid.size()); ++j) if (sid[j+1]-sid[j]-1 == len) {
                int li = sid[j]+1, ri = sid[j+1]-1;
                bool ok = true;
                for (int j2=0; j2<len; ++j2) if (board[i][li+j2]!=' ' && board[i][li+j2]!=word[j2]) {
                    ok = false;
                    break;
                }
                if (ok) {
                    res = true;
                    break;
                }
                ok = true;
                for (int j2=0; j2<len; ++j2) if (board[i][ri-j2]!=' ' && board[i][ri-j2]!=word[j2]) {
                    ok = false;
                    break;
                }
                if (ok) {
                    res = true;
                    break;
                }
            }
            if (res) break;
        }
        if (res) return true;
        for (int i=0; i<m; ++i) {
            vector<int> sid;
            sid.push_back(-1);
            for (int j=0; j<n; ++j) if (board[j][i] == '#') sid.push_back(j);
            sid.push_back(n);
            for (int j=0; j+1<(int)(sid.size()); ++j) if (sid[j+1]-sid[j]-1 == len) {
                int ui = sid[j]+1, di = sid[j+1]-1;
                bool ok = true;
                for (int j2=0; j2<len; ++j2) if (board[ui+j2][i]!=' ' && board[ui+j2][i]!=word[j2]) {
                    ok = false;
                    break;
                }
                if (ok) {
                    res = true;
                    break;
                }
                ok = true;
                for (int j2=0; j2<len; ++j2) if (board[di-j2][i]!=' ' && board[di-j2][i]!=word[j2]) {
                    ok = false;
                    break;
                }
                if (ok) {
                    res = true;
                    break;
                }
            }
            if (res) break;
        }
        if (res) return true;
        else return false;
    }
};
