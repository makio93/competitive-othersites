// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> alst;
        for (int i=0; i<n; ++i) {
            alst.emplace_back(intervals[i][0], 1);
            alst.emplace_back(intervals[i][1]+1, -1);
        }
        sort(alst.begin(), alst.end());
        int res = 0, val = 0;
        for (auto& pi : alst) {
            val += pi.second;
            res = max(res, val);
        }
        return res;
    }
};
