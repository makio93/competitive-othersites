// 本番AC

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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        UnionFind d(n);
        for (int i=0; i<m; ++i) d.unite(edges[i][0], edges[i][1]);
        unordered_map<int, int> ecnt;
        for (int i=0; i<n; ++i) ecnt[d.find(i)] = 0;
        for (int i=0; i<m; ++i) ecnt[d.find(edges[i][0])]++;
        int res = 0;
        for (const auto& pi : ecnt) {
            int gsz = d.size(pi.first);
            if (gsz*(gsz-1)/2 == pi.second) ++res;
        }
        return res;
    }
};
