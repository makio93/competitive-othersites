// 解説1TLE

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [&](auto& li, auto& ri) -> bool { return li[1] < ri[1]; });
        int mval = courses[n-1][1];
        vector<vector<int>> memo(n+1, vector<int>(mval+1, -1));
        auto dfs = [&](auto dfs, int id=0, int ti=0) -> int {
            if (memo[id][ti] != -1) return memo[id][ti];
            if (id == n) return memo[id][ti] = 0;
            int val = dfs(dfs, id+1, ti);
            if (ti+courses[id][0] <= courses[id][1]) val = max(val, dfs(dfs, id+1, ti+courses[id][0]) + 1);
            return memo[id][ti] = val;
        };
        return dfs(dfs);
    }
};
