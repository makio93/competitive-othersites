#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番後,自力AC

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    ll res = 0;
    vector<unordered_map<int, ll>> rl(n);
    for (int l=0; l<n; l+=2) {
        ll mval = c[l] - 1, nval = c[l];
        rep3(r, l+1, n) {
            if (r%2 == 1) {
                nval -= c[r];
                if (mval >= 0) res += max(0LL, mval-max(0LL,nval)+1LL);
                mval = min(mval, nval);
                if (nval < 0) rl[n-r-1][n-l-1] = (-nval) - 1;
            }
            else nval += c[r];
        }
    }
    reverse(all(c));
    for (int l=0; l<n; l+=2) {
        if (rl[l].empty()) continue; 
        ll mval = c[l] - 1, nval = c[l];
        rep3(r, l+1, n) {
            if (r%2 == 1) {
                nval -= c[r];
                if (rl[l].find(r)!=rl[l].end() && mval>=0) res += max(0LL, min(mval,rl[l][r])-max(0LL,nval)+1LL);
                mval = min(mval, nval);
            }
            else nval += c[r];
            if (min(mval, rl[l][r]) < 0) break;
        }
    }
    cout << res << endl;
    return 0;
}
