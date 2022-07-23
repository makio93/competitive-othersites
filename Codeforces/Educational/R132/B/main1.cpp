// 解説AC

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
    vector<int> lvals(n), rvals(n);
    rep3(i, 1, n) lvals[i] = max(0, a[i-1]-a[i]);
    rep(i, n-1) rvals[i] = max(0, a[i+1]-a[i]);
    vector<ll> lsums(n+1), rsums(n+1);
    rep(i, n) lsums[i+1] = lsums[i] + lvals[i];
    rep(i, n) rsums[i+1] = rsums[i] + rvals[i];
    rep(i, m) {
        int si, ti;
        cin >> si >> ti;
        if (ti > si) cout << (lsums[ti]-lsums[si]) << endl;
        else cout << (rsums[si-1]-rsums[ti-1]) << endl;
    }
    return 0;
}
