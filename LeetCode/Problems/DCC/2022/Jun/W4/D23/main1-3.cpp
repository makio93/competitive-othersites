// 解説3AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [&](auto& li, auto& ri) -> bool { return li[1] < ri[1]; });
        int tval = 0, res = 0;
        for (int i=0; i<n; ++i) {
            if (tval+courses[i][0] <= courses[i][1]) {
                tval += courses[i][0];
                courses[res][0] = courses[i][0];
                ++res;
            }
            else {
                int tid = i;
                for (int j=0; j<res; ++j) if (courses[j][0] > courses[tid][0]) tid = j;
                if (courses[tid][0] > courses[i][0]) {
                    tval += courses[i][0] - courses[tid][0];
                    courses[tid][0] = courses[i][0];
                }
            }
        }
        return res;
    }
};
