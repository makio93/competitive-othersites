// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n);
        vector<int> din(n);
        for (int i=0; i<n; ++i) if (edges[i] != -1) din[edges[i]]++;
        queue<int> que;
        for (int i=0; i<n; ++i) if (din[i] == 0) que.push(i);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            visited[vi] = true;
            if (edges[vi] == -1) continue;
            din[edges[vi]]--;
            if (din[edges[vi]] == 0) que.push(edges[vi]);
        }
        int res = -1;
        for (int i=0; i<n; ++i) if (!visited[i]) {
            int cnt = 1, vi = i;
            visited[vi] = true;
            while (!visited[edges[vi]]) {
                ++cnt;
                vi = edges[vi];
                visited[vi] = true;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
