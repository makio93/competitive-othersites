// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    rep(i, n-1) {
        int ui, vi, xi;
        cin >> ui >> vi >> xi;
        --ui; --vi; --xi;
        g[ui].emplace_back(vi, xi);
        g[vi].emplace_back(ui, xi);
    }
    vector<vector<int>> rlst(n), vlst(n);
    vector<int> plst(n, -1), clst(n, -1), tlst(n), svals(n);
    auto dfs0 = [&](auto& dfs0, int vi=0, int pi=-1) -> void {
        svals[vi]++;
        for (const auto& tpi : g[vi]) if (tpi.first != pi) {
            plst[tpi.first] = tlst[tpi.second];
            if (tlst[tpi.second] == 0) rlst[tpi.second].push_back(tpi.first);
            else vlst[plst[tpi.first]].push_back(tpi.first);
            clst[tpi.first] = tpi.second;
            tlst[tpi.second] = tpi.first;
            dfs0(dfs0, tpi.first, vi);
            svals[vi] += svals[tpi.first];
            tlst[tpi.second] = plst[tpi.first];
        }
    };
    dfs0(dfs0);
    vector<int> rvals(n), vvals(n);
    rep(i, n) if (!rlst[i].empty()) {
        rvals[i] = svals[0];
        for (const int& ti : rlst[i]) rvals[i] -= svals[ti];
    }
    rep3(i, 1, n) {
        vvals[i] = svals[i];
        for (const int& ti : vlst[i]) vvals[i] -= svals[ti];
    }
    ll res = 0;
    rep3(i, 1, n) res += (ll)vvals[i] * (plst[i] == 0 ? rvals[clst[i]] : vvals[plst[i]]);
    cout << res << endl;
    return 0;
}
