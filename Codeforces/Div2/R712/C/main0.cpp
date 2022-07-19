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
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n%2 != 0) {
            cout << "NO" << endl;
            continue;
        }
        int zero = 0, one = 0;
        rep(i, n) {
            if (s[i] == '0') ++zero;
            else ++one;
        }
        if (zero%2!=0 || one%2!=0) {
            cout << "NO" << endl;
            continue;
        }
        string a, b;
        int zcnt = 0, ocnt = 0;
        rep(i, n) {
            if (s[i] == '0') {
                if (zcnt%2==0) {
                    a += '(';
                    b += ')';
                }
                else {
                    a += ')';
                    b += '(';
                }
                ++zcnt;
            }
            else {
                ++ocnt;
                if (ocnt <= one/2) {
                    a += '(';
                    b += '(';
                }
                else  {
                    a += ')';
                    b += ')';
                }
            }
        }
        bool ok = true;
        int acnt = 0, bcnt = 0;
        rep(i, n) {
            if (a[i] == '(') ++acnt;
            else --acnt;
            if (b[i] == '(') ++bcnt;
            else --bcnt;
            if (acnt<0 || bcnt<0) ok = false;
        }
        if (ok) {
            cout << "YES" << endl;
            cout << a << endl;
            cout << b << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
