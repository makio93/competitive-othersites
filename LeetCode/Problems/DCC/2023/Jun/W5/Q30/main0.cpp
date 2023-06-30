// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
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
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        vector<vector<bool>> exists(row, vector<bool>(col, true));
        for (int i=0; i<n; ++i) exists[cells[i][0]-1][cells[i][1]-1] = false;
        UnionFind uf(row*col+2);
        for (int i=0; i<col; ++i) {
            if (exists[0][i]) uf.unite(i, row*col);
            if (exists[row-1][i]) uf.unite((row-1)*col+i, row*col+1);
        }
        for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) if (exists[i][j]) for (int i2=0; i2<4; ++i2) {
            int ni = i + di[i2], nj = j + dj[i2];
            if (ni<0 || ni>=row || nj<0 || nj>=col || !exists[ni][nj]) continue;
            uf.unite(i*col+j, ni*col+nj);
        }
        int res = n;
        for (int i=n-1; i>=0; --i) {
            if (uf.same(row*col, row*col+1)) break;
            int vi = cells[i][0] - 1, vj = cells[i][1] - 1;
            exists[vi][vj] = true;
            for (int i2=0; i2<4; ++i2) {
                int ni = vi + di[i2], nj = vj + dj[i2];
                if (ni<0 || ni>=row || nj<0 || nj>=col || !exists[ni][nj]) continue;
                uf.unite(vi*col+vj, ni*col+nj);
            }
            if (vi == 0) uf.unite(vi*col+vj, row*col);
            if (vi == row-1) uf.unite(vi*col+vj, row*col+1);
            --res;
        }
        return res;
    }
};
