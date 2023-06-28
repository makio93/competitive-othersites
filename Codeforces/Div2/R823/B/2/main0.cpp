// 学習2回目,自力AC

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
        vector<int> x(n), t(n);
        rep(i, n) cin >> x[i];
        rep(i, n) cin >> t[i];
        vector<int> xlst;
        rep(i, n) {
            xlst.push_back(x[i]-t[i]);
            xlst.push_back(x[i]+t[i]);
        }
        sort(all(xlst));
        cout << fixed << setprecision(10) << ((xlst.front()+xlst.back())/2.0) << endl;
    }
    return 0;
}
