// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(2e9);
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
        vector<int> ord(m);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int li, int ri) -> bool {
            return edgeList[li][2] < edgeList[ri][2];
        });
        UnionFind d(n);
        vector<vector<pair<int, int>>> g(n+1);
        for (int i=0; i<m; ++i) {
            int ei = ord[i];
            if (!d.same(edgeList[ei][0], edgeList[ei][1])) {
                d.unite(edgeList[ei][0], edgeList[ei][1]);
                g[edgeList[ei][0]].emplace_back(edgeList[ei][1], edgeList[ei][2]);
                g[edgeList[ei][1]].emplace_back(edgeList[ei][0], edgeList[ei][2]);
            }
        }
        unordered_set<int> gids;
        for (int i=0; i<n; ++i) gids.insert(d.find(i));
        for (const int& ti : gids) {
            g[n].emplace_back(ti, INF);
            g[ti].emplace_back(n, INF);
        }
        int blen = 1, bcnt = 1;
        while (bcnt*2 <= n+1) {
            ++blen;
            bcnt *= 2;
        }
        vector<int> dep(n+1);
        vector<vector<pair<int, int>>> dp(blen, vector<pair<int, int>>(n+1, { -1, INF }));
        auto dfs = [&](auto& dfs, int di=0, int vi=0, int pi=-1) -> void {
            dep[vi] = di;
            for (const auto& tpi : g[vi]) if (tpi.first != pi) {
                dp[0][tpi.first] = { vi, tpi.second };
                dfs(dfs, di+1, tpi.first, vi);
            }
        };
        dfs(dfs);
        for (int i=0; i<blen-1; ++i) for (int j=0; j<n+1; ++j) {
            if (dp[i][j].first==-1 || dp[i][dp[i][j].first].first==-1) continue;
            dp[i+1][j] = { dp[i][dp[i][j].first].first, max(dp[i][j].second, dp[i][dp[i][j].first].second) };
        }
        vector<bool> res(q);
        for (int i=0; i<q; ++i) {
            int pi = queries[i][0], qi = queries[i][1], di = 0;
            if (dep[pi] > dep[qi]) swap(pi, qi);
            while (dep[qi]-dep[pi] > 0) {
                for (int j=0; j<blen; ++j) if ((dep[qi]-dep[pi])&(1<<j)) {
                    di = max(di, dp[j][qi].second);
                    qi = dp[j][qi].first;
                    break;
                }
            }
            if (pi != qi) {
                for (int j=blen-1; j>=0; --j) {
                    if (dp[j][pi].first==-1 || dp[j][qi].first==-1 || dp[j][pi].first==dp[j][qi].first) continue;
                    di = max({ di, dp[j][pi].second, dp[j][qi].second });
                    pi = dp[j][pi].first;
                    qi = dp[j][qi].first;
                }
                if (pi != qi) di = max({ di, dp[0][pi].second, dp[0][qi].second });
            }
            res[i] = di < queries[i][2];
        }
        return res;
    }
};
