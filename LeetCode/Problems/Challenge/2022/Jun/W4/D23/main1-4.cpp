// 解説4AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [&](auto& li, auto& ri) -> bool { return li[1] < ri[1]; });
        int tval = 0;
        vector<int> clst;
        for (int i=0; i<n; ++i) {
            if (tval+courses[i][0] <= courses[i][1]) {
                tval += courses[i][0];
                clst.push_back(courses[i][0]);
            }
            else if (!clst.empty()) {
                int tid = 0;
                for (int j=1; j<(int)(clst.size()); ++j) if (clst[j] > clst[tid]) tid = j;
                if (clst[tid] > courses[i][0]) {
                    tval += courses[i][0] - clst[tid];
                    clst[tid] = courses[i][0];
                }
            }
        }
        return (int)(clst.size());
    }
};
