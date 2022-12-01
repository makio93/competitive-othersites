#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int main() {
    int n;
    cin >> n;
    vector<vector<int>> res(n, vector<int>(n));
    rep(i, n) rep(j, n) {
        if (i+j < n-1) res[i][j] = 0;
        else if (i+j==n-1 && i<j) res[i][j] = 1;
        else res[i][j] = 2;
    }
    rep(i, n) {
        rep(j, n) cout << res[i][j];
        cout << endl;
    }
    return 0;
}
