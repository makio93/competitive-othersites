// 学習1回目,自力WA

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
        int n;
        cin >> n;
        vector<int> x(n), t(n);
        rep(i, n) cin >> x[i];
        rep(i, n) cin >> t[i];
        vector<pair<int, int>> xids(n);
        rep(i, n) xids[i] = { x[i], t[i] };
        sort(all(xids));
        rep(i, n) {
            x[i] = xids[i].first;
            t[i] = xids[i].second;
        }
        double lv = 0.0, rv = (double)(x[n-1]);
        while ((rv-lv)/rv >= 1e-6) {
            double cv = (lv+rv) / 2.0, sum = 0.0;
            rep(i, n) {
                if ((double)(x[i]) <= cv) sum += cv - x[i] + t[i];
                else sum += cv - x[i] - t[i];
            }
            if (sum >= 0.0) rv = cv;
            else lv = cv;
        }
        cout << fixed << setprecision(10) << lv << endl;
    }
    return 0;
}
