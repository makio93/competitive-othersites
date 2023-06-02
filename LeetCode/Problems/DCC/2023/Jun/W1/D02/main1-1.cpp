// 解説AC1

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
        function<int(int,int,vector<bool>&)> dfs = [&](int vi, int pi, vector<bool>& visited) {
            int cnt = 1;
            visited[vi] = true;
            for (const int& ti : g[vi]) if (!visited[ti]) cnt += dfs(ti, vi, visited);
            return cnt;
        };
        vector<bool> visited;
        for (int i=0; i<n; ++i) {
            visited.assign(n, false);
            res = max(res, dfs(i, -1, visited));
        }
        return res;
    }
};
