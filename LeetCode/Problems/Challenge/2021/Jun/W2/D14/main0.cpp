#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<pair<int, int>> plst(n);
        for (int i=0; i<n; ++i) plst[i] = { boxTypes[i][1], boxTypes[i][0] };
        sort(plst.rbegin(), plst.rend());
        int res = 0;
        for (int i=0; i<n; ++i) {
            res += min(truckSize, plst[i].second) * plst[i].first;
            truckSize -= plst[i].second;
            if (truckSize <= 0) break;
        }
        return res;
    }
};
