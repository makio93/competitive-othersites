#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

const ll BIAS = (ll)(1e9);

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), m(n);
    vector<vector<int>> b(n);
    rep(i, n) {
        cin >> a[i] >> m[i];
        vector<int> bi(m[i]);
        rep(j, m[i]) {
            cin >> bi[j];
            bi[j]--;
        }
        b[i] = bi;
    }
    mcf_graph<int, ll> g(n);
    rep(i, n-1) g.add_edge(i, i+1, k, BIAS);
    rep(i, n) rep(j, m[i]) g.add_edge(b[i][j], i, 1, (a[b[i][j]]-a[i])+(i-b[i][j])*BIAS);
    auto p = g.flow(0, n-1, k);
    ll res = -(p.second - (n-1) * k * BIAS);
    cout << res << endl;
    return 0;
}
