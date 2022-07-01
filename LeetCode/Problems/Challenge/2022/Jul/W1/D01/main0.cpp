// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto& vl, auto& vr) -> bool {
            return vl[1] > vr[1];
        });
        int res = 0;
        for (auto& vi : boxTypes) {
            int sub = min(truckSize, vi[0]);
            res += vi[1] * sub;
            truckSize -= sub;
            if (truckSize == 0) break;
        }
        return res;
    }
};
