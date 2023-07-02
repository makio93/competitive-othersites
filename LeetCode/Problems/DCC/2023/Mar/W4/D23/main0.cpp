// 自力AC

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if ((int)(connections.size()) < n-1) return -1;
        UnionFind uf(n);
        for (int i=0; i<m; ++i) uf.unite(connections[i][0], connections[i][1]);
        int res = 0;
        for (int i=0; i<n; ++i) if (uf.find(i) == i) ++res;
        --res;
        return res;
    }
};
