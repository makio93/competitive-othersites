// 学習1回目,解説AC1

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
        vector<int> a(n), b;
        rep(i, n) cin >> a[i];
        int li = 0, ri = INF + 1;
        while (ri-li > 1) {
            int ci = li + (ri-li) / 2;
            b.assign(all(a));
            int ki = k;
            rep(i, n) if (b[i]*2 < ci) {
                b[i] = INF;
                --ki;
            }
            bool ok = ki >= 0;
            if (ok) {
                if (ki==1 && *max_element(all(b))<ci) ok = false;
                if (ki == 0) {
                    int mval = 0;
                    rep(i, n-1) mval = max(mval, min(b[i], b[i+1]));
                    if (mval < ci) ok = false;
                }
            }
            if (ok) li = ci;
            else ri = ci;
        }
        cout << li << endl;
    }
    return 0;
}
