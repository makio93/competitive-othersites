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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> lsum(n), rsum(n);
    rep3(i, 1, n) lsum[i] = lsum[i-1] + (a[i-1]-a[i]>0 ? a[i-1]-a[i] : 0);
    repr(i, n-1) rsum[i] = rsum[i+1] + (a[i+1]-a[i]>0 ? a[i+1]-a[i] : 0);
    rep(i, m) {
        int si, ti;
        cin >> si >> ti;
        --si; --ti;
        if (ti > si) cout << (lsum[ti]-lsum[si]) << endl;
        else cout << (rsum[ti]-rsum[si]) << endl;
    }
    return 0;
}
