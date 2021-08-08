#include <bits/stdc++.h>
using namespace std;

// 自力AC(+hints)

class Solution {
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
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size();
        vector<int> rows(n), cols(m);
        map<int, vector<int>> vals;
        for (int i=0; i<n*m; ++i) vals[matrix[i/m][i%m]].push_back(i);
        vector<vector<int>> res(n, vector<int>(m));
        for (auto p : vals) {
            UnionFind d(n+m);
            for (int id : p.second) d.unite(id/m, n+id%m);
            unordered_map<int, int> mvals;
            for (int id : p.second) {
                int mval = max(rows[id/m], cols[id%m]) + 1;
                if (mvals.find(d.find(id/m)) == mvals.end()) mvals[d.find(id/m)] = mval;
                else mvals[d.find(id/m)] = max(mvals[d.find(id/m)], mval);
            }
            for (int id : p.second) {
                res[id/m][id%m] = mvals[d.find(id/m)];
                rows[id/m] = max(rows[id/m], res[id/m][id%m]);
                cols[id%m] = max(cols[id%m], res[id/m][id%m]);
            }
        }
        return res;
    }
};
