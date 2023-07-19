// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](auto& li, auto& ri) -> bool { return li[1] < ri[1]; });
        int rval = -INF, res = 0;
        for (int i=0; i<n; ++i) {
            if (intervals[i][0] < rval) ++res;
            else rval = intervals[i][1];
        }
        return res;
    }
};
