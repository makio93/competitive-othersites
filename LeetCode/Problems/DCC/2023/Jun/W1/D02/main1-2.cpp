// 解説AC2

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
        function<int(int)> dfs = [&](int si) {
            vector<bool> visited(n);
            stack<int> st;
            visited[si] = true;
            st.push(si);
            while (!st.empty()) {
                int vi = st.top(); st.pop();
                for (const int& ti : g[vi]) if (!visited[ti]) {
                    visited[ti] = true;
                    st.push(ti);
                }
            }
            return (int)count(visited.begin(), visited.end(), true);
        };
        for (int i=0; i<n; ++i) res = max(res, dfs(i));
        return res;
    }
};
