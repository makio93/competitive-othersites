// 自力AC2,Space削減

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return (a[1] != b[1]) ? (a[1] < b[1]) : (a[0] > b[0]);
        });
        stack<int> st;
        for (int i=0; i<n; ++i) {
            while (!st.empty() && st.top()>=intervals[i][0]) st.pop();
            st.push(intervals[i][0]);
        }
        return (int)(st.size());
    }
};
