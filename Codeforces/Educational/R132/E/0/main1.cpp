// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int xi, yi;
        cin >> xi >> yi;
        --xi; --yi;
        g[xi].push_back(yi);
        g[yi].push_back(xi);
    }
    vector<int> svals(n);
    auto dfs0 = [&](auto dfs0, int vi=0, int pi=-1) -> void {
        svals[vi] = a[vi];
        if (pi != -1) svals[vi] ^= svals[pi];
        for (int ti : g[vi]) if (ti != pi) dfs0(dfs0, ti, vi);
    };
    dfs0(dfs0);
    vector<unordered_set<int>> vals(n);
    int res = 0;
    auto dfs1 = [&](auto dfs1, int vi=0, int pi=-1) -> void {
        vals[vi].insert(svals[vi]);
        for (int ti : g[vi]) if (ti != pi) dfs1(dfs1, ti, vi);
        bool bad = false;
        for (int ti : g[vi]) if (ti != pi) {
            if (vals[ti].size() > vals[vi].size()) swap(vals[ti], vals[vi]);
            for (int tval : vals[ti]) if (vals[vi].find(tval^a[vi]) != vals[vi].end()) bad = true;
            for (int tval : vals[ti]) vals[vi].insert(tval);
            vals[ti].clear();
        }
        if (bad) {
            ++res;
            vals[vi].clear();
        }
    };
    dfs1(dfs1);
    cout << res << endl;
    return 0;
}
