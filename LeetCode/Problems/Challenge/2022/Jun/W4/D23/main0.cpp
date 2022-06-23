// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int li, int ri) -> bool {
            return make_pair(courses[li][1], courses[li][0]) < make_pair(courses[ri][1], courses[ri][0]);
        });
        int val = 0;
        priority_queue<int> pq;
        for (int i=0; i<n; ++i) {
            val += courses[ord[i]][0];
            pq.push(courses[ord[i]][0]);
            if (val > courses[ord[i]][1]) {
                val -= pq.top();
                pq.pop();
            }
        }
        return (int)(pq.size());
    }
};
