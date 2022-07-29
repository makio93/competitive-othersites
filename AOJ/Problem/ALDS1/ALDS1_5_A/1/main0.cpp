// 復習1回目,自力,TLE

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
    int n, q;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    cin >> q;
    vector<int> mi(q);
    rep(i, q) cin >> mi[i];
    rep(i1, q) {
        bool ok = false;
        rep(i, 1<<n) {
            int sum = 0;
            rep(j, n) if ((i>>j)&1) {
                sum += a[j];
                if (sum > mi[i1]) break;
            }
            if (sum == mi[i1]) {
                ok = true;
                break;
            }
        }
        if (ok) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
