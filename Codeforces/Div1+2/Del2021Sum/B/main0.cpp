#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
    int t;
    cin >> t;
    rep(i0, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        vector<int> pcnt(2);
        rep(i, n) pcnt[a[i]%2]++;
        if (abs(pcnt[0]-pcnt[1]) != n%2) {
            cout << -1 << endl;
            continue;
        }
        vector<vector<int>> ids(2), lcnt(n, vector<int>(2)), rcnt(n, vector<int>(2));
        vector<int> lsum(2), rsum(2);
        rep(i, n) {
            ids[a[i]%2].push_back(i);
            rep(j, 2) lcnt[i][j] = lsum[j];
            lsum[a[i]%2]++;
        }
        repr(i, n) {
            rep(j, 2) rcnt[i][j] = rsum[j];
            rsum[a[i]%2]++;
        }
        ll res = (ll)(1e15);
        rep(i, 2) {
            if (n%2==1 && pcnt[i]<pcnt[1-i]) continue;
            ll cnt = 0;
            for (int j=0; j<n; j+=2) {
                int ti = j / 2, id2 = ids[i][ti];
                cnt += abs(ti-lcnt[id2][1-i]);
            }
            res = min(res, cnt);
        }
        cout << res << endl;
    }
    return 0;
}
