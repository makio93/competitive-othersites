// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        UnionFind uf(n);
        for (int i=0; i<m; ++i) uf.unite(edges[i][0], edges[i][1]);
        vector<int> slst;
        for (int i=0; i<n; ++i) if (uf.find(i) == i) slst.push_back(uf.size(i));
        ll res = 0;
        int slen = slst.size(), ssum = 0;
        for (int i=0; i<slen; ++i) {
            res += (ll)ssum * slst[i];
            ssum += slst[i];
        }
        return res;
    }
};
