// 学習1回目,解説AC1

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
    vector<vector<pair<int, int>>> g(n);
    rep(i, n-1) {
        int vi, ui, wi;
        cin >> vi >> ui >> wi;
        --vi; --ui; --wi;
        g[vi].emplace_back(ui, wi);
        g[ui].emplace_back(vi, wi);
    }
    vector<int> gcnt(n), ord, in(n, -1), out(n, -1), pw(n, -1);
    auto init = [&](auto init, int tm=0, int vi=0, int pi=-1) -> int {
        in[vi] = tm++;
        ord.push_back(vi);
        gcnt[vi]++;
        for (auto& tpi : g[vi]) if (tpi.first != pi) {
            pw[tpi.first] = tpi.second;
            tm = init(init, tm, tpi.first, vi);
            gcnt[vi] += gcnt[tpi.first];
        }
        return out[vi] = tm;
    };
    init(init);
    vector<vector<int>> wlst(n, vector<int>(1, 0));
    rep(i, n) for (auto& tpi : g[ord[i]]) if (wlst[tpi.second].back() != ord[i]) wlst[tpi.second].push_back(ord[i]);
    auto ispar = [&](int vi, int ui) -> bool { return in[vi] < in[ui] && out[ui] <= out[vi]; };
    ll res = 0;
    vector<vector<int>> tg(n);
    vector<vector<ll>> dp(n, vector<ll>(2));
    rep(i, n) if (!wlst[i].empty()) {
        stack<int> st;
        for (const int& ti : wlst[i]) {
            while (!st.empty() && !ispar(st.top(),ti)) st.pop();
            if (!st.empty()) tg[st.top()].push_back(ti);
            st.push(ti);
        }
        auto dfs = [&](auto dfs, int vi=0) -> ll {
            ll rval = 0;
            dp[vi][0] = gcnt[vi];
            dp[vi][1] = 0;
            for (const int& ti : tg[vi]) {
                rval += dfs(dfs, ti);
                dp[vi][0] -= gcnt[ti];
            }
            for (const int& ti : tg[vi]) {
                if (pw[ti] == i) {
                    rval += dp[ti][0] * dp[vi][0];
                    dp[vi][1] += dp[ti][0];
                }
                else {
                    rval += dp[ti][1] * dp[vi][0];
                    rval += dp[ti][0] * dp[vi][1];
                    dp[vi][0] += dp[ti][0];
                    dp[vi][1] += dp[ti][1];
                }
            }
            return rval;
        };
        res += dfs(dfs);
        for (const int& ti : wlst[i]) tg[ti].clear();
    }
    cout << res << endl;
    return 0;
}
