// 解説AC

#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int sz;
    vector<int> d;
    UnionFind(int n=0) : sz(n), d(n, -1) {}
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
        --sz;
        return true;
    }
    bool same(int x, int y) { return (find(x) == find(y)); }
    int size(int x) { return -d[find(x)]; }
    bool connected() { return sz == 1; }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int m = edges.size(), ecnt = 0;
        UnionFind uf1(n), uf2(n);
        for (int i=0; i<m; ++i) if (edges[i][0] == 3) {
            ecnt += (uf1.unite(edges[i][1]-1, edges[i][2]-1) | uf2.unite(edges[i][1]-1, edges[i][2]-1)) ? 1 : 0;
        }
        for (int i=0; i<m; ++i) if (edges[i][0] != 3) {
            ecnt += (edges[i][0] == 1 ? uf1.unite(edges[i][1]-1, edges[i][2]-1) : uf2.unite(edges[i][1]-1, edges[i][2]-1)) ? 1 : 0;
        }
        return (uf1.connected() && uf2.connected()) ? m - ecnt : -1;
    }
};
