#include <bits/stdc++.h>
using namespace std;

// 自力AC2

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> xlst, res;
        if (x == 1) xlst.push_back(1);
        else {
            long long tval = 1;
            while (tval < (long long)bound) {
                xlst.push_back((int)tval);
                tval *= x;
            }
        }
        if (x == y) {
            int m = xlst.size();
            for (int i=0; i<m; ++i) for (int j=i; j<m; ++j) if (xlst[i]+xlst[j] <= bound) res.push_back(xlst[i]+xlst[j]);
        }
        else {
            vector<int> ylst;
            if (y == 1) ylst.push_back(1);
            else {
                long long tval = 1;
                while (tval < (long long)bound) {
                    ylst.push_back((int)tval);
                    tval *= y;
                }
            }
            for (int xi : xlst) for (int yi : ylst) if (xi+yi <= bound) res.push_back(xi+yi);
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
