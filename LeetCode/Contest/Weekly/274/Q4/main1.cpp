#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> dist(n, -1);
        vector<vector<int>> rg(n);
        for (int i=0; i<n; ++i) rg[favorite[i]].push_back(i);
        int ans1 = 0, ans2 = 0;
        for (int i=0; i<n; ++i) if (dist[i] == -1) {
            if (favorite[favorite[i]] == i) {
                function<int(int,int)> dfs = [&](int vi, int pi) -> int {
                    if (dist[vi] != -1) return 0;
                    dist[vi] = 0;
                    int mval = 0;
                    for (int ti : rg[vi]) if (ti != pi) mval = max(mval, dfs(ti, vi));
                    return mval + 1;
                };
                ans1 += dfs(i, favorite[i]) + dfs(favorite[i], i);
            }
        }
        for (int i=0; i<n; ++i) if (dist[i] == -1) {
            function<int(int)> dfs2 = [&](int vi) -> int {
                if (dist[vi] != -1) return -1;
                dist[vi] = 0;
                if (dist[favorite[vi]] == -1) {
                    int val = dfs2(favorite[vi]);
                    if (val == -1) return val;
                    if (dist[vi] == 1) {
                        ans2 = max(ans2, val+1);
                        dist[vi] = 0;
                        return -1;
                    }
                    else return val + 1;
                }
                else {
                    dist[favorite[vi]] = 1;
                    return 1;
                }
            };
            dfs2(i);
        }
        return max(ans1, ans2);
    }
};
