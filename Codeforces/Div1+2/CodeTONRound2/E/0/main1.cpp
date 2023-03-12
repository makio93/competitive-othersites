// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

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
        vector<int> dout(n);
        vector<vector<int>> g(n), rg(n);
        rep(i, m) {
            int xi, yi;
            cin >> xi >> yi;
            --xi; --yi;
            g[xi].push_back(yi);
            rg[yi].push_back(xi);
            dout[xi]++;
        }
        vector<ll> b(n);
        rep(i, n) b[i] = a[i];
        int res = -1;
        rep(i1, n) {
            auto tmp = b;
            bool exist = false;
            rep(i, n) {
                if (b[i] > 0) {
                    tmp[i]--;
                    for (int ti : g[i]) tmp[ti]++;
                    if (!exist) exist = true;
                }
            }
            if (!exist) {
                res = i1;
                break;
            }
            swap(b, tmp);
        }
        if (res != -1) {
            cout << res << endl;
            continue;
        }
        res = n;
        vector<ll> vcnt(n);
        int rid = -1;
        rep(i, n) if (dout[i] == 0) {
            rid = i;
            break;
        }
        vcnt[rid] = 1;
        queue<int> que;
        que.push(rid);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            ll val = vcnt[vi];
            for (int ti : rg[vi]) {
                vcnt[ti] = (vcnt[ti] + val) % mod;
                dout[ti]--;
                if (dout[ti] == 0) que.push(ti);
            }
        }
        rep(i, n) res = (res + vcnt[i] * b[i]) % mod;
        cout << res << endl;
    }
    return 0;
}
