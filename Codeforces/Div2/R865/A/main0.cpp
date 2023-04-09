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
        int a, b;
        cin >> a >> b;
        vector<pair<int, int>> res;
        if (gcd(a, b) == 1) res.emplace_back(a, b);
        else {
            res.emplace_back(a-1, a);
            res.emplace_back(a, b);
        }
        int m = res.size();
        cout << m << endl;
        rep(i, m) cout << res[i].first << ' ' << res[i].second << endl;
    }
    return 0;
}
