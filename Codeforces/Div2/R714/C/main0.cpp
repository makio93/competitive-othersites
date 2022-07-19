// 本番TLE

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

const ll mod = (ll)(1e9)+7;
v(v(ll)) memo;
ll calc(int m, int d) {
    if (memo[m][d] != -1LL) return memo[m][d];
    if (d+m <= 9) return (memo[m][d] = 1);
    else {
        ll res = 0;
        int m2 = m - (10-d);
        res = (calc(m2, 1) + calc(m2, 0)) % mod;
        return (memo[m][d] = res);
    }
}

int main(){
    int t;
    cin >> t;
    memo = v(v(ll))((int)(3e5)+35, v(ll)(10, -1));
    rep(i1, t) {
        string nstr;
        int m;
        cin >> nstr >> m;
        ll ans = 0;
        rep(i, sz(nstr)) ans = (ans + calc(m, (int)(nstr[i]-'0'))) % mod;
        cout << ans << endl;
    }
    return 0;
}
