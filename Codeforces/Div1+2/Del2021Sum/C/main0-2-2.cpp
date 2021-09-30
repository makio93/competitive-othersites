#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番後,自力AC,2

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    ll res = 0;
    for (int l=0; l<n; l+=2) {
        ll mval = c[l], nval = mval;
        rep3(r, l+1, n) {
            if (r%2 == 1) {
                nval -= c[r];
                if (r == l+1) res += max(0LL, mval-max(0LL,nval));
                else res += max(0LL, mval-max(0LL,nval)+1LL);
                mval = min(mval, nval);
            }
            else nval += c[r];
            if (mval < 0) break;
        }
    }
    cout << res << endl;
    return 0;
}
