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
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        int n = sz(s);
        if (n%2==1) {
            if (s[n/2] == '0') --a;
            else if (s[n/2] == '1') --b;
        }
        int l = 0, r = n-1;
        bool ok = true;
        while (l < r) {
            if (s[l]!='?' || s[r]!='?') {
                if (s[l]!='?' && s[r]!='?') {
                    if (s[l]==s[r]) {
                        if (s[l] == '0') a -= 2;
                        else b -= 2;
                    }
                    else ok = false;
                }
                else {
                    if (s[l]!='?') {
                        s[r] = s[l];
                        if (s[l] == '0') a -= 2;
                        else b -= 2;
                    }
                    else {
                        s[l] = s[r];
                        if (s[r] == '0') a -= 2;
                        else b -= 2;
                    }
                }
            }
            if (!ok) break;
            ++l; --r;
        }
        if (!ok || (a<0||b<0)) {
            cout << -1 << endl;
            continue;
        }
        l = 0; r = n-1;
        while (l < r) {
            if (s[l]=='?' && s[r]=='?') {
                if (a >= 2) {
                    s[l] = s[r] = '0';
                    a -= 2;
                }
                else if (b >= 2) {
                    s[l] = s[r] = '1';
                    b -= 2;
                }
                else ok = false;
            }
            if (!ok) break;
            ++l; --r;
        }
        if (!ok || (a<0||b<0)) {
            cout << -1 << endl;
            continue;
        }
        if (n%2==1 && s[n/2]=='?') {
            if (a==1&&b==0) {
                s[n/2] = '0';
                --a;
            }
            else if (a==0&&b==1) {
                s[n/2] = '1';
                --b;
            }
            else ok = false;
        }
        if (!ok || (a!=0||b!=0)) {
            cout << -1 << endl;
        }
        else {
            cout << s << endl;
        }
    }
    return 0;
}
