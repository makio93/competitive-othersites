// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rg(n);
        vector<int> din(n);
        for (int i=0; i<n; ++i) for (const int& ti : graph[i]) {
            rg[ti].push_back(i);
            din[i]++;
        }
        vector<int> res;
        queue<int> que;
        for (int i=0; i<n; ++i) if (din[i] == 0) {
            que.push(i);
            res.push_back(i);
        }
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            for (const int& ti : rg[vi]) if (din[ti] > 0) {
                din[ti]--;
                if (din[ti] == 0) {
                    que.push(ti);
                    res.push_back(ti);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
