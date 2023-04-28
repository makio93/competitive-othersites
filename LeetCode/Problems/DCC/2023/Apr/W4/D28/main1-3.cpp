// 解説AC3

#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parents, ranks;
    UnionFind(int n) {
        parents.resize(n, -1);
        ranks.assign(n, 0);
        for (int i=0; i<n; ++i) parents[i] = i;
    }
    int find(int x) {
        if (parents[x] != x) return parents[x] = find(parents[x]);
        return parents[x];
    }
    void unite(int x, int y) {
        int xi = find(x), yi = find(y);
        if (ranks[xi] == ranks[yi]) ranks[xi]++;
        if (ranks[xi] < ranks[yi]) parents[xi] = yi;
        else parents[yi] = xi;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size(), m = strs.front().length(), res = n;
        UnionFind dsu(n);
        auto similar = [&](int li, int ri) -> bool {
            int cnt = 0;
            for (int i=0; i<m; ++i) if (strs[li][i] != strs[ri][i]) ++cnt;
            return cnt <= 2;
        };
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) if (similar(i, j) && !dsu.same(i, j)) {
            --res;
            dsu.unite(i, j);
        }
        return res;
    }
};
