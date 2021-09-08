#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番実装,未完成

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> x, y;
        x.push_back(0);
        y.push_back(0);
        rep(i, n) {
            int xi;
            cin >> xi;
            x.push_back(xi);
        }
        rep(i, m) {
            int yi;
            cin >> yi;
            y.push_back(yi);
        }
        x.push_back((int)(1e6));
        y.push_back((int)(1e6));
        vector<unordered_map<int, int>> xidcnt(n), yidcnt(m); 
        vector<int> xcnt(n), ycnt(m);
        rep(i, k) {
            int xi, yi;
            cin >> xi >> yi;
            auto xid = lower_bound(all(x), xi), yid = lower_bound(all(y), yi);
            if (*xid != xi) {

            }
        }
    }
    return 0;
}
