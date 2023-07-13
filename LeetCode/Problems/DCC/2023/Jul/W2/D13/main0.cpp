// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> din(numCourses);
        for (const auto& vi : prerequisites) {
            g[vi[1]].push_back(vi[0]);
            din[vi[0]]++;
        }
        queue<int> que;
        for (int i=0; i<numCourses; ++i) if (din[i] == 0) que.push(i);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            for (const int& ti : g[vi]) if (din[ti] > 0) {
                din[ti]--;
                if (din[ti] == 0) que.push(ti);
            }
        }
        return count(din.begin(), din.end(), 0) == numCourses;
    }
};
