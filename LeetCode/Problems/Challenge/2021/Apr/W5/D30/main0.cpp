#include <bits/stdc++.h>
using namespace std;

// 自力AC1

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> xlst, ylst;
        if (x == 1) xlst.push_back(1);
        else {
            long long tval = 1;
            while (tval < (long long)bound) {
                xlst.push_back((int)tval);
                tval *= x;
            }
        }
        if (y == 1) ylst.push_back(1);
        else {
            long long tval = 1;
            while (tval < (long long)bound) {
                ylst.push_back((int)tval);
                tval *= y;
            }
        }
        vector<int> res;
        for (int xi : xlst) for (int yi : ylst) if (xi+yi <= bound) res.push_back(xi+yi);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
