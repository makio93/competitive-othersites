// 本番AC

#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        vi w(n);
        rep(i, n) cin >> w[i];
        vector<vi> g(n);
        rep(i, n-1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            g[u].pb(v);
            g[v].pb(u);
        }
        vi vals;
        rep(i, n) {
            if (sz(g[i]) <= 1) continue;
            int d = sz(g[i]) - 1;
            rep(j, d) vals.pb(w[i]);
        }
        RSORT(vals);
        ll sum = 0;
        rep(i, n) sum += w[i];
        vll ans;
        ans.pb(sum);
        ll now = sum;
        rep(i, n-2) {
            now += vals[i];
            ans.pb(now);
        }
        rep(i, sz(ans)) {
            printf("%lld%c", ans[i], (i<sz(ans)-1?' ':'\n'));
        }
    }
    return 0;
}
