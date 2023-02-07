#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res = 0;
        map<int, vector<int>> hlst;
        for (int i=0; i<n; ++i) hlst[heights[i]].push_back(i+1);
        set<int> vals;
        vals.insert(0);
        vals.insert(n+1);
        for (auto pvi : hlst) {
            for (int id : pvi.second) {
                auto litr = vals.lower_bound(id);
                int len = *litr - *prev(litr) - 1;
                res = max(res, len*pvi.first);
                vals.insert(id);
            }
        }
        return res;
    }
};
