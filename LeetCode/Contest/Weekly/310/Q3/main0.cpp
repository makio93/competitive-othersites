// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int MAX = (int)(1e6);
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> subs(MAX+2);
        for (int i=0; i<n; ++i) {
            subs[intervals[i][0]]++;
            subs[intervals[i][1]+1]--;
        }
        for (int i=0; i<=MAX; ++i) subs[i+1] += subs[i];
        return *max_element(subs.begin(), subs.end());
    }
};
