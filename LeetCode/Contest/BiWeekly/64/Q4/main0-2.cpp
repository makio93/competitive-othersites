#include <bits/stdc++.h>
using namespace std;

// バチャ本番WA2

class Solution {
    vector<string> types = { "rook", "queen", "bishop" };
    vector<vector<int>> dr = { { -1, 0, 1, 0 }, { -1, -1, 0, 1, 1, 1, 0, -1 }, { -1, 1, 1, -1 } }, 
        dc = { { 0, 1, 0, -1 }, { 0, 1, 1, 1, 0, -1, -1, -1 }, { 1, 1, -1, -1 } };
    int res = 0;
    set<int> pset;
    void dfs(vector<int>& tlst, vector<vector<int>>& splst, int d) {
        for (int i=0; i<(int)(dr[tlst[d]].size()); ++i) {
            int ri = splst[d][0], ci = splst[d][1], mul = ((i==0) ? 0 : 1);
            pset.erase(ri*(1<<3)+ci);
            while (mul <= 8) {
                int nri = ri + dr[tlst[d]][i] * mul, nci = ci + dc[tlst[d]][i] * mul;
                if (nri<0 || nri>=8 || nci<0 || nci>=8) break;
                int pval = nri * (1<<3) + nci;
                if (pset.find(pval) != pset.end()) break;
                if (d == (int)(tlst.size())-1) ++res;
                else {
                    pset.insert(pval);
                    dfs(tlst, splst, d+1);
                    pset.erase(pval);
                }
                ++mul;
            }
            pset.insert(ri*(1<<3)+ci);
        }
        pset.insert(splst[d][0]*(1<<3)+splst[d][1]);
    }
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int n = pieces.size();
        vector<int> tlst(n);
        vector<vector<int>> splst = positions;
        for (int i=0; i<n; ++i) for (int j=0; j<3; ++j) if (pieces[i] == types[j]) tlst[i] = j;
        for (int i=0; i<n; ++i) for (int j=0; j<2; ++j) positions[i][j]--;
        for (int i=0; i<n; ++i) pset.insert(positions[i][0]*(1<<3)+positions[i][1]);
        dfs(tlst, splst, 0);
        return res;
    }
};
