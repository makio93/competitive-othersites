#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int mval = targetSeconds / 60, sval = targetSeconds % 60, res = (int)(1e9);
        if (mval <= 99) {
            vector<int> vals(4);
            vals[0] = mval / 10; vals[1] = mval % 10;
            vals[2] = sval / 10; vals[3] = sval % 10;
            reverse(vals.begin(), vals.end());
            while (vals.back() == 0) vals.pop_back();
            reverse(vals.begin(), vals.end());
            int pos = startAt, sum = 0;
            for (int val : vals) {
                if (pos != val) sum += moveCost;
                pos = val;
                sum += pushCost;
            }
            res = min(res, sum);
        }
        if (mval-1>=0 && sval+60<=99) {
            --mval;
            sval += 60;
            vector<int> vals(4);
            vals[0] = mval / 10; vals[1] = mval % 10;
            vals[2] = sval / 10; vals[3] = sval % 10;
            reverse(vals.begin(), vals.end());
            while (vals.back() == 0) vals.pop_back();
            reverse(vals.begin(), vals.end());
            int pos = startAt, sum = 0;
            for (int val : vals) {
                if (pos != val) sum += moveCost;
                pos = val;
                sum += pushCost;
            }
            res = min(res, sum);
        }
        return res;
    }
};
