// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
    const vector<int> dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid.front().size(), k = queries.size();
        vector<vector<int>> dist(m, vector<int>(n, INF));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        dist[0][0] = grid[0][0] + 1;
        pq.emplace(grid[0][0]+1, 0, 0);
        while (!pq.empty()) {
            auto pi = pq.top(); pq.pop();
            int di = get<0>(pi), ri = get<1>(pi), ci = get<2>(pi);
            if (dist[ri][ci] != di) continue;
            for (int i1=0; i1<4; ++i1) {
                int nri = ri + dr[i1], nci = ci + dc[i1];
                if (nri<0 || nri>=m || nci<0 || nci>=n) continue;
                int ndi = max(di, grid[nri][nci]+1);
                if (dist[nri][nci] <= ndi) continue;
                dist[nri][nci] = ndi;
                pq.emplace(ndi, nri, nci);
            }
        }
        int mval = *max_element(queries.begin(), queries.end());
        vector<int> vals(mval+1);
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (dist[i][j] <= mval) vals[dist[i][j]]++;
        for (int i=0; i<mval; ++i) vals[i+1] += vals[i];
        vector<int> res(k);
        for (int i=0; i<k; ++i) res[i] = vals[queries[i]];
        return res;
    }
};
