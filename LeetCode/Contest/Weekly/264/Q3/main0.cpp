#include <bits/stdc++.h>
using namespace std;

// 本番AC

using ll = long long;

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> g(n);
        for (int i=1; i<n; ++i) {
            g[i].push_back(parents[i]);
            g[parents[i]].push_back(i);
        }
        vector<int> scnt(n);
        map<ll, int> rcnt;
        function<int(int,int)> dfs = [&](int v, int p) -> int {
            int val = 1;
            ll mul = 0;
            for (int ti : g[v]) if (ti != p) {
                val += dfs(ti, v);
                mul = (mul==0) ? scnt[ti] : mul*scnt[ti];
            }
            if (val < n) mul = (mul==0) ? (n-val) : mul*(n-val);
            rcnt[mul]++;
            return (scnt[v] = val);
        };
        dfs(0, -1);
        return rcnt.rbegin()->second;
    }
};
