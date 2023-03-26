// 解説AC0(自力実装)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
        }
        queue<int> que;
        for (int i=0; i<n; ++i) if (deg[i]==1 && coins[i]==0) que.push(i);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            if (deg[vi] == 0) continue;
            deg[vi]--;
            for (const int& ti : g[vi]) if (deg[ti] > 0) {
                deg[ti]--;
                if (deg[ti]==1 && coins[ti]==0) que.push(ti);
            }
        }
        for (int i=0; i<2; ++i) {
            for (int j=0; j<n; ++j) if (deg[j] == 1) que.push(j);
            while (!que.empty()) {
                int vi = que.front(); que.pop();
                if (deg[vi] == 0) continue;
                deg[vi]--;
                for (const int& ti : g[vi]) if (deg[ti] > 0) deg[ti]--;
            }
        }
        return accumulate(deg.begin(), deg.end(), 0);
    }
};
