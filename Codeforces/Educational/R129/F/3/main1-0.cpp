// 学習3回目,解説AC

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
        int vi, ui, xi;
        cin >> vi >> ui >> xi;
        --vi; --ui; --xi;
        g[vi].emplace_back(ui, xi);
        g[ui].emplace_back(vi, xi);
    }
    vector<vector<int>> xl(n, vector<int>(1, 0));
    vector<int> in(n, -1), out(n, -1), pid(n, -1), sz(n), ord;
    int tid = 0;
    function<void(int, int)> dfs0 = [&](int vi, int pi) {
        in[vi] = tid++;
        ord.push_back(vi);
        sz[vi] = 1;
        for (const auto& [tvi, txi] : g[vi]) if (tvi != pi) {
            pid[tvi] = txi;
            xl[txi].push_back(vi);
            xl[txi].push_back(tvi);
            dfs0(tvi, vi);
            sz[vi] += sz[tvi];
        }
        out[vi] = tid++;
    };
    dfs0(0, -1);
    vector<int> rord(n);
    rep(i, n) rord[ord[i]] = i;
    auto isp = [&](int ai, int bi) -> bool { return in[ai] < in[bi] && out[bi] < out[ai]; };
    vector<vector<int>> vg(n);
    vector<vector<int>> dp(n, vector<int>(2));
    ll res = 0;
    rep(i, n) {
        sort(all(xl[i]), [&](int& ai, int& bi) -> bool { return rord[ai] < rord[bi]; });
        xl[i].erase(unique(all(xl[i])), xl[i].end());
        stack<int> st;
        st.push(0);
        for (const int vj : xl[i]) if (vj != 0) {
            while (!isp(st.top(), vj)) st.pop();
            vg[st.top()].push_back(vj);
            st.push(vj);
        }
        function<void(int, int)> dfs1 = [&](int vi, int pi) {
            int add = sz[vi];
            for (const int& ti : vg[vi]) if (ti != pi) {
                dfs1(ti, vi);
                if (pid[ti] == i) {
                    add -= sz[ti];
                    dp[vi][1] += dp[ti][0];
                }
                else {
                    add -= sz[ti];
                    dp[vi][0] += dp[ti][0];
                    dp[vi][1] += dp[ti][1];
                }
            }
            dp[vi][0] += add;
            int zero = add, one = 0;
            for (const int& ti : vg[vi]) if (ti != pi) {
                if (pid[ti] == i) {
                    res += dp[ti][0] * (ll)zero;
                    one += dp[ti][0];
                }
                else {
                    res += dp[ti][1] * (ll)zero;
                    res += dp[ti][0] * (ll)one;
                    one += dp[ti][1];
                    zero += dp[ti][0];
                }
            }
        };
        dfs1(0, -1);
        for (const int vi : xl[i]) {
            vg[vi].clear();
            dp[vi][0] = dp[vi][1] = 0;
        }
    }
    cout << res << endl;
    return 0;
}
