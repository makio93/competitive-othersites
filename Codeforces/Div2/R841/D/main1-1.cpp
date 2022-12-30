// 解説AC1

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
        vector<vector<int>> sums(n+1, vector<int>(m+1));
        int li = 1, ri = min(n, m) + 1;
        while (ri-li > 1) {
            int ci = li + (ri-li) / 2;
            rep(i, n) rep(j, m) sums[i+1][j+1] = sums[i][j+1] + sums[i+1][j] - sums[i][j] + (a[i][j] >= ci ? 1 : 0);
            bool ok = false;
            for (int i=0; i+ci<=n; ++i) for (int j=0; j+ci<=m; ++j) 
                if (sums[i+ci][j+ci]-sums[i+ci][j]-sums[i][j+ci]+sums[i][j] >= ci*ci) ok = true;
            if (ok) li = ci;
            else ri = ci;
        }
        cout << li << endl;
    }
    return 0;
}
