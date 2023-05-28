// 本番WA1

#include <bits/stdc++.h>
using namespace std;

const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.front().size();
        vector<vector<int>> g(m*n);
        vector<int> din(m*n);
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) for (int i2=0; i2<4; ++i2) {
            int ni = i + di[i2], nj = j + dj[i2];
            if (ni<0 || ni>=m || nj<0 || nj>=n || mat[ni][nj]<=mat[i][j]) continue;
            g[i*n+j].push_back(ni*n+nj);
            din[ni*n+nj]++;
        }
        queue<int> que;
        vector<int> dist(m*n);
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (din[i*n+j] == 0) {
            que.push(i*n+j);
            dist[i*n+j] = max(dist[i*n+j], 1);
        }
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist[vi], ndi = di + 1;
            for (const int& ti : g[vi]) if (din[ti] > 0) {
                dist[ti] = max(dist[ti], ndi);
                din[ti]--;
                if (din[ti] == 0) que.push(ti);
            }
        }
        int res = 0;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) res = max(res, dist[i*n+j]);
        return res;
    }
};
