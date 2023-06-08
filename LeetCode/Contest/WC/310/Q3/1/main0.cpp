// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size(), mx = 0;
        for (int i=0; i<n; ++i) mx = max({ mx, intervals[i][0]-1, intervals[i][1] });
        vector<int> scnt(mx+1);
        for (int i=0; i<n; ++i) {
            scnt[intervals[i][0]-1]++;
            scnt[intervals[i][1]]--;
        }
        int res = 0;
        for (int i=0; i<mx; ++i) {
            res = max(res, scnt[i]);
            scnt[i+1] += scnt[i];
        }
        return res;
    }
};
