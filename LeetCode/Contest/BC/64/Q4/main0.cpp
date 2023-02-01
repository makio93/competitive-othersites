#include <bits/stdc++.h>
using namespace std;

// バチャ本番WA1

class Solution {
    vector<string> types = { "rook", "queen", "bishop" };
    vector<vector<int>> dr = { { -1, 0, 1, 0 }, { -1, -1, 0, 1, 1, 1, 0, -1 }, { -1, 1, 1, -1 } }, 
        dc = { { 0, 1, 0, -1 }, { 0, 1, 1, 1, 0, -1, -1, -1 }, { 1, 1, -1, -1 } };
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int n = pieces.size();
        vector<vector<vector<bool>>> moved(n, vector<vector<bool>>(8, vector<bool>(8)));
        for (int i=0; i<n; ++i) {
            int tval = -1;
            for (int j=0; j<3; ++j) if (types[j] == pieces[i]) tval = j;
            int ri = positions[i][0]-1, ci = positions[i][1]-1;
            moved[i][ri][ci] = true;
            for (int j=0; j<(int)(dr[tval].size()); ++j) {
                int mul = 1;
                while (mul <= 8) {
                    int nri = ri + dr[tval][j] * mul, nci = ci + dc[tval][j] * mul;
                    if (nri<0 || nri>=8 || nci<0 || nci>=8) break;
                    moved[i][nri][nci] = true;
                    ++mul;
                }
            }
        }
        int res = 0;
        for (int i=0; i<(1<<(n*6)); ++i) {
            vector<int> rs(n), cs(n);
            int tval = i;
            for (int j=0; j<n; ++j) {
                rs[j] = tval % (1<<3);
                tval /= (1<<3);
                cs[j] = tval % (1<<3);
                tval /= (1<<3);
            }
            map<pair<int, int>, int> tcnt;
            for (int j=0; j<n; ++j) tcnt[{rs[j], cs[j]}]++;
            bool ok = true;
            for (auto tpi : tcnt) if (tpi.second > 1) ok = false;
            if (!ok) continue;
            for (int j=0; j<n; ++j) if (!moved[j][rs[j]][cs[j]]) ok = false;
            if (ok) ++res;
        }
        return res;
    }
};
