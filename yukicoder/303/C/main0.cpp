#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番中に作成、解答がわからず未完成

int main() {
    int n;
    cin >> n;
    vector<vector<int>> b(n, vector<int>(n));
    set<int> memo;
    rep(i, n) rep(j, n) rep(k, 3) {
        b[i][j] = k;
        bool ok = true;
    }
    return 0;
}
