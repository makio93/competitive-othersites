// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int is_depth(int vi) {
        int di = 0;
        while (vi >= (1LL<<(di+1))) ++di;
        return di;
    }
    int lca_depth(int ai, int bi) {
        int adi = is_depth(ai), bdi = is_depth(bi);
        if (adi < bdi) {
            swap(adi, bdi);
            swap(ai, bi);
        }
        while (adi > bdi) {
            ai /= 2;
            --adi;
        }
        while (ai != bi) {
            ai /= 2;
            bi /= 2;
            --adi; --bdi;
        }
        return adi;
    }
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> res(m);
        for (int i=0; i<m; ++i) {
            int ldi = lca_depth(queries[i][0], queries[i][1]), adi = is_depth(queries[i][0]), bdi = is_depth(queries[i][1]);
            res[i] = (adi-ldi) + (bdi-ldi) + 1;
        }
        return res;
    }
};
