// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if (n == 1) return 0;
        sort(stockPrices.begin(), stockPrices.end(), [&](auto& lv, auto& rv){
            return lv[0] != rv[0] ? lv[0] < rv[0] : lv[1] < rv[1];
        });
        int cnt = 0, li = 0;
        while (li+1 < n) {
            int ri = li + 1;
            ll dx = stockPrices[ri][0] - stockPrices[li][0], dy = stockPrices[ri][1] - stockPrices[li][1];
            while (ri+1 < n) {
                ll ndx = stockPrices[ri+1][0] - stockPrices[li][0], ndy = stockPrices[ri+1][1] - stockPrices[li][1];
                if (dx*ndy != dy*ndx) break;
                ++ri;
            }
            ++cnt;
            li = ri;
        }
        return cnt;
    }
};
