// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int, int> acnts;
        for (int i=0; i<n; ++i) {
            acnts[intervals[i][0]]++;
            acnts[intervals[i][1]+1]--;
        }
        int res = 0, val = 0;
        for (auto& pi : acnts) {
            val += pi.second;
            res = max(res, val);
        }
        return res;
    }
};
