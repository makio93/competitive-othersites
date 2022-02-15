#include <bits/stdc++.h>
using namespace std;

// 解説から,TLE解2

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
        int rtime = 0, res = 0;
        for (int i=0; i<n; ++i) {
            if (rtime+courses[i][0] <= courses[i][1]) {
                rtime += courses[i][0];
                ++res;
            }
            else {
                int tid = i;
                for (int j=0; j<i; ++j) if (courses[j][0] > courses[tid][0]) tid = j;
                if (tid != i) rtime += courses[i][0] - courses[tid][0];
                courses[tid][0] = -1;
            }
        }
        return res;
    }
};