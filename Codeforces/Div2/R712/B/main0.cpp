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
        string a, b;
        cin >> a >> b;
        v(v(int)) asum(2, v(int)(n+1)), bsum(2, v(int)(n+1));
        rep(i, n) {
            rep(j, 2) {
                asum[j][i+1] = asum[j][i] + ((int)(a[i]-'0')==j?1:0);
                bsum[j][i+1] = bsum[j][i] + ((int)(b[i]-'0')==j?1:0);
            }
        }
        bool ok = true;
        int lpos = 0;
        rep2(i, 1, n) if (asum[0][i] == asum[1][i]) {
            if (bsum[0][i] != bsum[1][i]) ok = false;
            else {
                bool ok2 = true;
                rep2(j, lpos, i-1) if ((p(int)){asum[0][j],asum[1][j]} != (p(int)){bsum[0][j],bsum[1][j]}) ok2 = false;
                if (!ok2) {
                    ok2 = true;
                    rep2(j, lpos, i-1) if ((p(int)){asum[0][j],asum[1][j]} != (p(int)){bsum[1][j],bsum[0][j]}) ok2 = false;
                    if (!ok2) ok = false;
                }
            }
            if (!ok) break;
            lpos = i;
        }
        if (lpos < n) {
            rep2(i, lpos+1, n) if ((p(int)){asum[0][i],asum[1][i]} != (p(int)){bsum[0][i],bsum[1][i]}) ok = false;
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
