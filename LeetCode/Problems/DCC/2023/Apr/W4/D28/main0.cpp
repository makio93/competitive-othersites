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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size(), m = strs.front().length();
        UnionFind uf(n);
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            vector<int> ids;
            for (int k=0; k<m; ++k) if (strs[i][k] != strs[j][k]) {
                ids.push_back(k);
                if ((int)(ids.size()) > 2) break;
            }
            if ((int)(ids.size()) > 2) continue;
            uf.unite(i, j);
        }
        unordered_set<int> gids;
        for (int i=0; i<n; ++i) gids.insert(uf.find(i));
        return (int)(gids.size());
    }
};
