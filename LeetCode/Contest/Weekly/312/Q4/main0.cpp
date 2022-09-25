// 本番WA

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);

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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(), m = edges.size();
        vector<set<pair<int, int>>> tov(n);
        for (int i=0; i<m; ++i) {
            tov[edges[i][0]].emplace(vals[edges[i][1]], edges[i][1]);
            tov[edges[i][1]].emplace(vals[edges[i][0]], edges[i][0]);
        }
        int res = 0;
        map<int, unordered_set<int>> vlst;
        for (int i=0; i<n; ++i) vlst[vals[i]].insert(i);
        UnionFind uf(n);
        vector<unordered_map<int, int>> ulst(n);
        for (auto& pi : vlst) {
            int val = pi.first;
            for (const int& ti : pi.second) {
                ulst[uf.find(ti)][val]++;
                for (auto& tpi : tov[ti]) {
                    if (tpi.first > val) break;
                    int tval = tpi.first, toi = tpi.second;
                    if (!uf.same(ti, toi)) {
                        int aid = uf.find(ti), bid = uf.find(toi);
                        if (ulst[aid].size() < ulst[bid].size()) swap(aid, bid);
                        for (auto pi2 : ulst[bid]) ulst[aid][pi2.first] += pi2.second;
                        uf.unite(ti, toi);
                        int cid = uf.find(ti);
                        if (cid != aid) swap(ulst[cid], ulst[aid]);
                    }
                }
                res += ulst[uf.find(ti)][val];
            }
        }
        return res;
    }
};
