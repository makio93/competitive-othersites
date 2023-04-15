// 本番WA2

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
        vector<int> a(n), b(n);
        rep(i, n) cin >> a[i] >> b[i];
        vector<pair<int, int>> res;
        int hval = *max_element(all(a)), wval = *max_element(all(b));
        ll asum = 0, hsum = 0, wsum = 0;
        rep(i, n) asum += (ll)a[i] * b[i];
        rep(i, n) if (a[i] == hval) hsum += b[i];
        rep(i, n) if (b[i] == wval) wsum += a[i];
        if ((asum-hsum*hval)%hval == 0) res.emplace_back(hval, asum/hval);
        if ((asum-wsum*wval)%wval==0 && hval!=asum/wval) res.emplace_back(asum/wval, wval);
        int m = res.size();
        cout << m << endl;
        rep(i, m) cout << res[i].first << ' ' << res[i].second << endl;
    }
    return 0;
}
