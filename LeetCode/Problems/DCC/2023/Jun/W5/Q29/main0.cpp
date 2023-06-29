// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid.front().size(), k = 0, si = -1, sj = -1;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
            if (islower(grid[i][j])) k = max(k, grid[i][j]-'a'+1);
            if (grid[i][j] == '@') si = i, sj = j;
        }
        vector<vector<vector<int>>> dists(m, vector<vector<int>>(n, vector<int>(1<<k, INF)));
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
        pq.emplace(0, si, sj, 0);
        dists[si][sj][0] = 0;
        while (!pq.empty()) {
            auto [vdi, vi, vj, ki] = pq.top(); pq.pop();
            if (dists[vi][vj][ki] != vdi) continue;
            int ndi = vdi + 1;
            for (int i2=0; i2<4; ++i2) {
                int ni = vi + di[i2], nj = vj + dj[i2];
                if (ni<0 || ni>=m || nj<0 || nj>=n || grid[ni][nj]=='#') continue;
                int nki = ki;
                if (islower(grid[ni][nj])) nki |= 1<<(grid[ni][nj]-'a');
                if ((!isupper(grid[ni][nj]) || (nki>>(grid[ni][nj]-'A')&1)) && dists[ni][nj][nki]>ndi) {
                    pq.emplace(ndi, ni, nj, nki);
                    dists[ni][nj][nki] = ndi;
                }
            }
        }
        int res = INF;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) res = min(res, dists[i][j][(1<<k)-1]);
        return res == INF ? -1 : res;
    }
};
