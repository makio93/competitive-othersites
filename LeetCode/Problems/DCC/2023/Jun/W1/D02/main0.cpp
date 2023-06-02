// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> g(n);
        function<bool(int,int)> is_connected = [&](int ai, int bi) {
            return (ll)(bombs[ai][0]-bombs[bi][0]) * (bombs[ai][0]-bombs[bi][0]) + 
                (ll)(bombs[ai][1]-bombs[bi][1]) * (bombs[ai][1]-bombs[bi][1]) <= 
                (ll)bombs[ai][2] * bombs[ai][2];
        };
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (i != j && is_connected(i, j)) g[i].push_back(j);
        int res = 0;
        for (int i=0; i<n; ++i) {
            queue<int> que;
            vector<bool> dist(n);
            que.push(i);
            dist[i] = true;
            while (!que.empty()) {
                int vi = que.front(); que.pop();
                for (const int& ti : g[vi]) if (!dist[ti]) {
                    dist[ti] = true;
                    que.push(ti);
                }
            }
            res = max(res, (int)count(dist.begin(), dist.end(), true));
        }
        return res;
    }
};
