// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e8);
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i=0; i<n; ++i) dist[i][i] = 0;
        for (int i=0; i<n; ++i) for (int ti : graph[i]) dist[i][ti] = dist[ti][i] = 1;
        for (int k=0; k<n; ++k) for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            dist[i][j] = min({ dist[i][j], min(INF, dist[i][k]+dist[k][j]), min(INF, dist[j][k]+dist[k][i]) });
        }
        map<pair<int, int>, int> memo;
        function<int(int,int)> dfs = [&](int si, int vlst) -> int {
            if (memo.find({si, vlst}) != memo.end()) return memo[{si, vlst}];
            if (!((vlst>>si)&1)) return memo[{si, vlst}] = INF;
            if (vlst == (1<<n)-1) return memo[{si, vlst}] = 0;
            int rval = INF;
            for (int i=0; i<n; ++i) if (!((vlst>>i)&1)) rval = min(rval, min(INF, dfs(i, vlst|(1<<i))+dist[si][i]));
            return memo[{si, vlst}] = rval;
        };
        int res = (int)(1e9);
        for (int i=0; i<n; ++i) res = min(res, dfs(i, (1<<i)));
        return res;
    }
};
