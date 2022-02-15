#include <bits/stdc++.h>
using namespace std;

// 解説AC1,O(n*res),入力配列のソート処理以降の書き換え禁止

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
        vector<int> vlst;
        int rtime = 0;
        for (int i=0; i<n; ++i) {
            if (rtime+courses[i][0] <= courses[i][1]) {
                rtime += courses[i][0];
                vlst.push_back(courses[i][0]);
            }
            else if (!vlst.empty()) {
                int tid = 0, m = vlst.size();
                for (int j=1; j<m; ++j) if (vlst[j] > vlst[tid]) tid = j;
                if (vlst[tid] > courses[i][0]) {
                    rtime += courses[i][0] - vlst[tid];
                    vlst[tid] = courses[i][0];
                }
            }
        }
        return vlst.size();
    }
};
