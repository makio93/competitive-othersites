#include <bits/stdc++.h>
using namespace std;

// 解説から,TLE解1

class Solution {
    vector<unordered_map<int, int>> memo;
    int calc(vector<vector<int>>& courses, int v, int rtime) {
        if (memo[v].find(rtime) != memo[v].end()) return memo[v][rtime];
        if (v >= (int)(courses.size())) return memo[v][rtime] = 0;
        else {
            int res = calc(courses, v+1, rtime);
            if (rtime+courses[v][0] <= courses[v][1]) res = max(res, 1 + calc(courses, v+1, rtime+courses[v][0]));
            return memo[v][rtime] = res;
        }
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
        memo = vector<unordered_map<int, int>>(n+1);
        return calc(courses, 0, 0);
    }
};
