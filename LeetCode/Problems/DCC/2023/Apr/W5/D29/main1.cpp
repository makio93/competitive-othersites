// 解説AC

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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m = edgeList.size(), q = queries.size();
        vector<int> eids(m), qids(q);
        iota(eids.begin(), eids.end(), 0);
        iota(qids.begin(), qids.end(), 0);
        sort(eids.begin(), eids.end(), [&](int li, int ri) -> bool { return edgeList[li][2] < edgeList[ri][2]; });
        sort(qids.begin(), qids.end(), [&](int li, int ri) -> bool { return queries[li][2] < queries[ri][2]; });
        UnionFind d(n);
        vector<bool> res(q);
        int ei = 0;
        for (int i=0; i<q; ++i) {
            while (ei<m && edgeList[eids[ei]][2]<queries[qids[i]][2]) {
                d.unite(edgeList[eids[ei]][0], edgeList[eids[ei]][1]);
                ++ei;
            }
            res[qids[i]] = d.same(queries[qids[i]][0], queries[qids[i]][1]);
        }
        return res;
    }
};
