// 学習1回目,自力AC

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
    int n;
    cin >> n;
    vector<int> r(n), c(n);
    rep(i, n) cin >> r[i] >> c[i];
    vector<vector<int>> dp(n, vector<int>(n, INF));
    rep(i, n) dp[i][i] = 0;
    auto f = [&](int li, int ci, int ri) -> int { return r[li] * c[ri] * r[ci]; };
    rep3(i1, 2, n+1) for (int i=0; i+i1<=n; ++i) rep3(j, 1, i1) {
        dp[i][i+i1-1] = min(dp[i][i+i1-1], dp[i][i+j-1]+dp[i+j][i+i1-1]+f(i,i+j,i+i1-1));
    }
    cout << dp[0][n-1] << endl;
    return 0;
}
