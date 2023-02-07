// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> vlst(n);
        for (int i=0; i<n; ++i) vlst[i] = { intervals[i][1], -intervals[i][0] };
        sort(vlst.begin(), vlst.end());
        stack<int> st;
        for (int i=0; i<n; ++i) {
            while (!st.empty() && st.top()>=-vlst[i].second) st.pop();
            st.push(-vlst[i].second);
        }
        return (int)(st.size());
    }
};
