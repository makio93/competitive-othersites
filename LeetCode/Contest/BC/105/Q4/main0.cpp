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
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, unordered_set<int>> plst;
        UnionFind uf(n);
        for (int i=0; i<n; ++i) {
            int val = nums[i];
            for (int j=2; j*j<=val; ++j) if (val%j == 0) {
                if (plst.find(j) != plst.end()) uf.unite(i, *plst[j].begin());
                plst[j].insert(i);
                while (val%j == 0) val /= j;
            }
            if (val > 1) {
                if (plst.find(val) != plst.end()) uf.unite(i, *plst[val].begin());
                plst[val].insert(i);
            }
        }
        return uf.size(0) == n;
    }
};
