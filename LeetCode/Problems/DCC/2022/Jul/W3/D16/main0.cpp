// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = (int)(1e9) + 7;
    const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dist(m, vector<int>(n)), ndist;
        vector<vector<bool>> visited;
        int res = 0;
        queue<pair<int, int>> que;
        que.emplace(startRow, startColumn);
        dist[startRow][startColumn] = 1;
        while (!que.empty() && maxMove--) {
            ndist.assign(m, vector<int>(n));
            visited.assign(m, vector<bool>(n));
            int len = que.size();
            while (len--) {
                auto pi = que.front(); que.pop();
                int ri = pi.first, ci = pi.second;
                int di = dist[ri][ci];
                for (int i=0; i<4; ++i) {
                    int nri = ri + dy[i], nci = ci + dx[i];
                    if (nri<0 || nri>=m || nci<0 || nci>=n) res = (res + di) % mod;
                    else {
                        ndist[nri][nci] = (ndist[nri][nci] + di) % mod;
                        if (!visited[nri][nci]) {
                            que.emplace(nri, nci);
                            visited[nri][nci] = true;
                        }
                    }
                }
            }
            swap(dist, ndist);
        }
        return res;
    }
};
