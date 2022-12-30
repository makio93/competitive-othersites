// ヒント有,自力AC

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
        int li = 1, ri = min(n, m) + 1;
        vector<vector<int>> dp(n, vector<int>(m));
        while (ri-li > 1) {
            int ci = li + (ri-li) / 2, mval = 0, tcnt = 0;
            rep(i, m) dp[0][i] = (a[0][i] >= ci) ? 1 : 0;
            rep(i, m) {
                if (dp[0][i] >= ci) ++tcnt;
                else {
                    mval = max(mval, tcnt);
                    tcnt = 0;
                }
            }
            mval = max(mval, tcnt);
            rep3(i, 1, n) {
                rep(j, m) {
                    if (a[i][j] >= ci) dp[i][j] = dp[i-1][j] + 1;
                    else dp[i][j] = 0;
                }
                tcnt = 0;
                rep(j, m) {
                    if (dp[i][j] >= ci) ++tcnt;
                    else {
                        mval = max(mval, tcnt);
                        tcnt = 0;
                    }
                }
                mval = max(mval, tcnt);
            }
            if (mval >= ci) li = ci;
            else ri = ci;
        }
        cout << li << endl;
    }
    return 0;
}
