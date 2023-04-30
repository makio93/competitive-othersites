// 自力AC1

#include <bits/stdc++.h>
using namespace std;

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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int m = edges.size(), ecnt = 0;
        sort(edges.rbegin(), edges.rend());
        vector<UnionFind> uf(2, UnionFind(n));
        for (int i=0; i<m; ++i) {
            bool uni = false;
            for (int j=0; j<2; ++j) if ((edges[i][0]&(1<<j)) && !uf[j].same(edges[i][1]-1, edges[i][2]-1)) uni = true;
            if (uni) {
                for (int j=0; j<2; ++j) if (edges[i][0]&(1<<j)) uf[j].unite(edges[i][1]-1, edges[i][2]-1);
                ++ecnt;
            }
        }
        return (uf[0].size(0) == n && uf[1].size(0) == n) ? m - ecnt : -1;
    }
};
