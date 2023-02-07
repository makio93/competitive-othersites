#include <bits/stdc++.h>
using namespace std;

// 解説AC2,O(n*log(n))解

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){ return make_pair(a[1], a[0]) < make_pair(b[1], b[0]); });
        priority_queue<int> pq;
        int rtime = 0;
        for (int i=0; i<n; ++i) {
            if (rtime+courses[i][0] <= courses[i][1]) {
                rtime += courses[i][0];
                pq.push(courses[i][0]);
            }
            else {
                if (!pq.empty() && pq.top()>courses[i][0]) {
                    rtime += courses[i][0] - pq.top();
                    pq.pop(), pq.push(courses[i][0]);
                }
            }
        }
        return (int)pq.size();
    }
};
