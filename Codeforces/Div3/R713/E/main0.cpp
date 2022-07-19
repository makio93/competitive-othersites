// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        int len = r - l + 1, sval = 0;
        rep(i, len) sval += i+1;
        if (sval > s) {
            cout << -1 << endl;
            continue;
        }
        int svalt2 = 0;
        rep(i, len) svalt2 += (n-i);
        if (svalt2 < s) {
            cout << -1 << endl;
            continue;
        }
        if (len >= n) {
            int svalt = (n+1)*n/2;
            if (svalt == s) {
                rep(i, n) {
                    cout << (i+1) << ((i<n-1)?' ':'\n');
                }
                continue;
            }
            else {
                cout << -1 << endl;
                continue;
            }
        }
        int lpos = -1, ival = -1;
        set<int> choosed;
        for (int i=len; i>=1; --i) {
            int sval2 = sval + (n - i);
            if (s>=sval && s<=sval2) {
                lpos = i - 1;
                ival = i + ((n-i) - (sval2-s));
                rep2(i2, 1, lpos) choosed.insert(i2);
                choosed.insert(ival);
                int rev = len-(lpos+1);
                rep(i2, rev) choosed.insert(n-i2);
                break;
            }
        }
        if (choosed.empty()) {
            cout << -1 << endl;
            continue;
        }
        else {
            v(int) pi(n);
            int tpos = l-1;
            repi(itr, choosed) {
                pi[tpos] = *itr;
                ++tpos;
            }
            tpos = 0;
            rep2(i, 1, n) if (choosed.find(i) == choosed.end()) {
                if (tpos>=l-1 && tpos<=r-1) tpos = r;
                if (tpos >= n) break;
                pi[tpos] = i;
                ++tpos;
            }
            rep(i, n) printf("%d%c", pi[i], (i<n-1?' ':'\n'));
        }
    }
    return 0;
}
