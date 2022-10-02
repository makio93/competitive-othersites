// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    ll minimumMoney(vector<vector<int>>& transactions) {
        int n = transactions.size();
        vector<vector<int>> nega, posi;
        for (int i=0; i<n; ++i) {
            if (transactions[i][1]-transactions[i][0] < 0) nega.push_back({ transactions[i][0], transactions[i][1] });
            else posi.push_back({ transactions[i][0], transactions[i][1] });
        }
        ll res = 0, val = 0;
        int nlen = nega.size(), plen = posi.size();
        if (nlen > 0) {
            vector<int> ord(nlen);
            iota(ord.begin(), ord.end(), 0);
            sort(ord.begin(), ord.end(), [&](auto li, auto ri) -> bool {
                return make_pair(nega[li][1], nega[li][0]) < make_pair(nega[ri][1], nega[ri][0]);
            });
            for (int i=0; i<nlen-1; ++i) val += nega[ord[i]][1] - nega[ord[i]][0];
            res = -(val - nega[ord[nlen-1]][0]);
            val += nega[ord[nlen-1]][1] - nega[ord[nlen-1]][0];
        }
        if (plen > 0) {
            int pval = 0;
            for (int i=0; i<plen; ++i) pval = max(pval, posi[i][0]);
            res = max(res, -(val-pval));
        }
        return res;
    }
};
