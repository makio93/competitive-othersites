// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> vlst;
        for (int i=0; i<n; ++i) {
            vlst.emplace_back(intervals[i][0], 1);
            vlst.emplace_back(intervals[i][1]+1, -1);
        }
        sort(vlst.begin(), vlst.end());
        int val = 0, res = 0;
        for (const auto& pi : vlst) {
            val += pi.second;
            res = max(res, val);
        }
        return res;
    }
};
