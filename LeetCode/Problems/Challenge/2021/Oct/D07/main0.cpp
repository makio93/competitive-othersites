#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board.front().size(), len = word.length();
        string rword = word;
        reverse(rword.begin(), rword.end());
        priority_queue<pair<int, pair<bool, vector<int>>>, vector<pair<int, pair<bool, vector<int>>>>, greater<pair<int, pair<bool, vector<int>>>>> que;
        int dcnt = 0, rcnt = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (word.front() == board[i][j]) {
            if (len > 1) que.emplace(1, make_pair(false, vector<int>({ i*m+j })));
            else return true;
            ++dcnt;
        }
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (rword.front() == board[i][j]) {
            if (len > 1) que.emplace(1, make_pair(true, vector<int>({ i*m+j })));
            else return true;
            ++rcnt;
        }
        while (!que.empty() && dcnt>0 && rcnt>0) {
            auto [d, pvl] = que.top(); que.pop();
            auto vl = pvl.second;
            int v = vl.back(), y = v / m, x = v % m, nd = d + 1;
            const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            bool ri = pvl.first;
            if (!ri) --dcnt;
            else --rcnt;
            for (int i=0; i<4; ++i) {
                int ny = y + dy[i], nx = x + dx[i], nv = ny * m + nx;
                if (ny<0 || ny>=n || nx<0 | nx>=m) continue;
                if (find(vl.begin(), vl.end(), nv) != vl.end()) continue;
                if (!ri && board[ny][nx]!=word[d]) continue;
                if (ri && board[ny][nx]!=rword[d]) continue;
                if (nd == len) return true;
                auto nvl = vl;
                nvl.push_back(nv);
                que.emplace(nd, make_pair(ri, nvl));
                if (!ri) ++dcnt;
                else ++rcnt;
            }
        }
        return false;
    }
};
