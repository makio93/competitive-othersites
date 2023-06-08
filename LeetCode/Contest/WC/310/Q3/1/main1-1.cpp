// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size(), res = 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i=0; i<n; ++i) {
            while (!pq.empty() && pq.top()<intervals[i][0]) pq.pop();
            pq.push(intervals[i][1]);
            res = max(res, (int)(pq.size()));
        }
        return res;
    }
};
