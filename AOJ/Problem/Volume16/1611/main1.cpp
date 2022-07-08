// 復習2回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> w(n);
        rep(i, n) cin >> w[i];
        vector<vector<bool>> take(n, vector<bool>(n));
        rep3(k, 1, n) rep(l, n) {
            int r = l + k;
            if (r >= n) break;
            rep3(c, l+1, r+1) take[l][r] = take[l][r] || (take[l][c-1] && take[c][r]);
            if (r-l+1 == 2) take[l][r] = abs(w[r]-w[l]) <= 1;
            if (take[l][r]) {
                int x = l - 1, y = r + 1;
                while (x>=0 && y<n && abs(w[x]-w[y])<=1) {
                    take[x][y] = true;
                    --x; ++y;
                }
            }
        }
        vector<vector<int>> dp(n, vector<int>(n));
        rep(l, n) rep3(r, l, n) if (take[l][r]) dp[l][r] = r - l + 1;
        rep3(k, 1, n) rep(l, n) {
            int r = l + k;
            if (r >= n) break;
            rep3(c, l+1, r+1) dp[l][r] = max(dp[l][r], dp[l][c-1]+dp[c][r]);
        }
        cout << dp[0][n-1] << endl;
    }
    return 0;
}
