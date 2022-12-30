// 解説AC2

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
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        rep(i, n) rep(j, m) cin >> a[i][j];
        int mval = min(n, m), klen = 1;
        while ((1<<(klen-1)) < mval) ++klen;
        vector<vector<vector<int>>> st(n, vector<vector<int>>(m, vector<int>(klen)));
        rep(i, n) rep(j, m) st[i][j][0] = a[i][j];
        rep3(k, 1, klen) for (int i=0; i+(1<<k)-1<n; ++i) for (int j=0; j+(1<<k)-1<m; ++j) 
            st[i][j][k] = min({ st[i][j][k-1], st[i][j+(1<<(k-1))][k-1], st[i+(1<<(k-1))][j][k-1], st[i+(1<<(k-1))][j+(1<<(k-1))][k-1] });
        int li = 1, ri = min(n, m) + 1;
        while (ri-li > 1) {
            int ci = li + (ri-li) / 2, bi = 0;
            while ((1<<(bi+1)) <= ci) ++bi;
            bool ok = false;
            for (int i=0; i+ci-1<n; ++i) for (int j=0; j+ci-1<m; ++j) 
                if (min({ st[i][j][bi], st[i+ci-(1<<bi)][j][bi], st[i][j+ci-(1<<bi)][bi], st[i+ci-(1<<bi)][j+ci-(1<<bi)][bi] }) >= ci) ok = true;
            if (ok) li = ci;
            else ri = ci;
        }
        cout << li << endl;
    }
    return 0;
}
