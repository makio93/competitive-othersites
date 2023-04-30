// 解説AC1

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
    vector<int> sz(n), px(n, -1), ord, din(n, -1), dout(n, -1);
    int di = 0;
    auto tour = [&](auto& tour, int vi=0, int pi=-1) -> void {
        din[vi] = di++;
        ord.push_back(vi);
        sz[vi]++;
        for (const auto [ti, xi] : g[vi]) if (ti != pi) {
            tour(tour, ti, vi);
            sz[vi] += sz[ti];
            px[ti] = xi;
        }
        dout[vi] = di;
    };
    tour(tour);
    vector<vector<int>> sord(n, vector<int>(1, 0));
    for (const int& vi : ord) for (const auto tpi : g[vi]) if (sord[tpi.second].back() != vi) sord[tpi.second].push_back(vi);
    auto isa = [&](int vi, int ti) -> bool {
        return din[ti] <= din[vi] && dout[ti] >= dout[vi];
    };
    ll res = 0;
    vector<vector<int>> ng(n);
    vector<vector<int>> dp(n, vector<int>(2));
    stack<int> st;
    rep(i, n) if ((int)(sord[i].size()) > 1) {
        auto& tord = sord[i];
        for (const int& vi : tord) {
            if (st.empty()) {
                st.push(vi);
                continue;
            }
            while (!isa(vi, st.top())) st.pop();
            ng[st.top()].push_back(vi);
            st.push(vi);
        }
        while (!st.empty()) st.pop();
        auto dfs = [&](auto& dfs, int vi=0, int pi=-1) -> ll {
            ll rval = 0;
            dp[vi][0] = sz[vi];
            dp[vi][1] = 0;
            for (const int& ti : ng[vi]) if (ti != pi) dp[vi][0] -= sz[ti];
            for (const int& ti : ng[vi]) if (ti != pi) {
                rval += dfs(dfs, ti, vi);
                if (px[ti] == i) {
                    rval += dp[vi][0] * (ll)dp[ti][0];
                    dp[vi][1] += dp[ti][0];
                }
                else {
                    rval += dp[vi][0] * (ll)dp[ti][1];
                    rval += dp[vi][1] * (ll)dp[ti][0];
                    dp[vi][0] += dp[ti][0];
                    dp[vi][1] += dp[ti][1];
                }
            }
            return rval;
        };
        res += dfs(dfs);
        for (const int& vi : tord) ng[vi].clear();
    }
    cout << res << endl;
    return 0;
}
