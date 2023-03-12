// 学習1回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
const ll mod = 998244353LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        vector<vector<int>> g(n), rg(n);
        vector<int> deg(n);
        rep(i, m) {
            int xi, yi;
            cin >> xi >> yi;
            --xi; --yi;
            g[xi].push_back(yi);
            rg[yi].push_back(xi);
            deg[xi]++;
        }
        ll res = 0;
        vector<int> na;
        rep(i, n) {
            na.assign(n, 0);
            bool fin = true;
            rep(j, n) {
                if (a[j] > 0) {
                    if (fin) fin = false;
                    na[j] += a[j] - 1;
                    for (const int& ti : g[j]) na[ti]++;
                }
            }
            swap(na, a);
            if (fin) break;
            ++res;
        }
        if (res < n) {
            cout << res << endl;
            continue;
        }
        vector<ll> dp(n);
        queue<int> que;
        rep(i, n) if (deg[i] == 0) {
            dp[i] = 1;
            que.push(i);
        }
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            ll di = dp[vi];
            for (const int& ti : rg[vi]) {
                dp[ti] += di;
                dp[ti] %= mod;
                deg[ti]--;
                if (deg[ti] == 0) que.push(ti);
            }
        }
        rep(i, n) {
            res += dp[i] * a[i] % mod;
            res %= mod;
        }
        cout << res << endl;
    }
    return 0;
}
