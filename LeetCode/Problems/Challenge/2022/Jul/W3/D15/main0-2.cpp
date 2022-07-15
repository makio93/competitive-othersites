// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct UnionFind {
        vector<int> d;
        UnionFind(int n=0) : d(n, -1) {}
        int find(int x) {
            if (d[x] < 0) return x;
            return (d[x] = find(d[x]));
        }
        bool unite(int x, int y) {
            x = find(x); y = find(y);
            if (x == y) return false;
            if (d[x] > d[y]) swap(x, y);
            d[x] += d[y];
            d[y] = x;
            return true;
        }
        bool same(int x, int y) { return (find(x) == find(y)); }
        int size(int x) { return -d[find(x)]; }
    };
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        UnionFind ds(m*n);
        int res = 0;
        for (int y=0; y<m; ++y) for (int x=0; x<n; ++x) if (grid[y][x] == 1) {
            static const array<int, 4> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            for (int i=0; i<4; ++i) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny<0 || ny>=m || nx<0 || nx>=n || grid[ny][nx]==0) continue;
                ds.unite(y*n+x, ny*n+nx);
            }
            res = max(res, ds.size(y*n+x));
        }
        return res;
    }
};
