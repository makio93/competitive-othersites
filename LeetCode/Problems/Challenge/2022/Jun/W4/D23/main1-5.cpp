// 解説5AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [&](auto& li, auto& ri) -> bool { return li[1] < ri[1]; });
        int tval = 0;
        priority_queue<int> pq;
        for (auto& ci : courses) {
            if (tval+ci[0] <= ci[1]) {
                tval += ci[0];
                pq.push(ci[0]);
            }
            else if (!pq.empty() && pq.top()>ci[0]) {
                tval += ci[0] - pq.top();
                pq.pop();
                pq.push(ci[0]);
            }
        }
        return (int)(pq.size());
    }
};
