// 解説AC1

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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        int li = 1, ri = INF+1;
        while (ri-li > 1) {
            int ci = li + (ri-li) / 2, kcnt = 0;
            auto b = a;
            rep(i, n) if (b[i]*2 < ci) {
                b[i] = INF;
                ++kcnt;
            }
            if (kcnt > k) ri = ci;
            else if (k-kcnt>=2 || (k-kcnt==1&&kcnt>=1)) li = ci;
            else if (k-kcnt == 1) {
                bool ok = false;
                rep(i, n-1) if (min(INF, max(b[i], b[i+1])) >= ci) {
                    ok = true;
                    break;
                }
                if (ok) li = ci;
                else ri = ci;
            }
            else {
                bool ok = false;
                rep(i, n-1) if (min(b[i], b[i+1]) >= ci) {
                    ok = true;
                    break;
                }
                if (ok) li = ci;
                else ri = ci;
            }
        }
        cout << li << endl;
    }
    return 0;
}
