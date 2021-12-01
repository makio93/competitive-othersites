#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

const int INF = (int)(1e9);

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
        vector<int> ord(n);
        rep(i, n) ord[i] = i;
        sort(all(ord), [&a](int x, int y){ return (a[x] > a[y]); });
        vector<vector<int>> lmx(n, vector<int>(m, 0)), rmn(n, vector<int>(m, INF));
        repr(i, n) rep(j, m) {
            lmx[i][j] = a[ord[i]][j];
            if (i+1 < n) lmx[i][j] = max(lmx[i][j], lmx[i+1][j]);
            if (j-1 >= 0) lmx[i][j] = max(lmx[i][j], lmx[i][j-1]);
        }
        repr(i, n) repr(j, m) {
            rmn[i][j] = a[ord[i]][j];
            if (i+1 < n) rmn[i][j] = min(rmn[i][j], rmn[i+1][j]);
            if (j+1 < m) rmn[i][j] = min(rmn[i][j], rmn[i][j+1]);
        }
        vector<int> lmn(m, INF), rmx(m, 0);
        pair<int, int> res = { -1, -1 };
        rep(i, n-1) {
            rep(j, m) {
                lmn[j] = min(lmn[j], a[ord[i]][j]);
                if (j-1 >= 0) lmn[j] = min(lmn[j], lmn[j-1]);
            }
            repr(j, m) {
                rmx[j] = max(rmx[j], a[ord[i]][j]);
                if (j+1 < m) rmx[j] = max(rmx[j], rmx[j+1]);
            }
            rep(j, m-1) if (lmn[j]>lmx[i+1][j] && rmx[j+1]<rmn[i+1][j+1]) {
                res = { i, j };
                break;
            }
            if (res.first != -1) break;
        }
        if (res.first != -1) {
            string cols(n, '.');
            rep(i, n) cols[ord[i]] = (i<=res.first) ? 'R' : 'B';
            cout << "YES" << endl;
            cout << cols << ' ' << (res.second+1) << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
