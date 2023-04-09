// 本番AC

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
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n;
        cin >> n;
        vector<vector<int>> res(2, vector<int>(n));
        rep(i, n/2) {
            res[1][i*2] = i*2 + 1;
            res[0][i*2+1] = i*2 + 2;
        }
        rep(i, n/2) {
            res[1][i*2+1] = i*2 + 1 + n;
            res[0][(i*2+2)%n] = i*2 + 2 + n;
        }
        rep(i, 2) rep(j, n) cout << res[i][j] << (j<n-1?' ':'\n');
    }
    return 0;
}
