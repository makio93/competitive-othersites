// 本番AC

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
        string s;
        cin >> s;
        string s1 = s + 'a', s2 = 'a' + s;
        bool ok = false;
        int l = 0, r = sz(s1) - 1;
        while (l<r) {
            if (s1[l] != s1[r]) {
                ok = true;
                break;
            }
            else { ++l; --r; }
        }
        if (ok) {
            cout << "YES" << endl;
            cout << s1 << endl;
            continue;
        }
        l = 0; r = sz(s2) - 1;
        while (l<r) {
            if (s2[l] != s2[r]) {
                ok = true;
                break;
            }
            else { ++l; --r; }
        }
        if (ok) {
            cout << "YES" << endl;
            cout << s2 << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}
