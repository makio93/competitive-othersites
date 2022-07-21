// 終了後,自力考察,TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;

struct mint {
    ll x;
    mint(ll x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

struct combination {
    vector<mint> fact, ifact;
    combination(int n) : fact(n+1), ifact(n+1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i=1; i<=n; ++i) fact[i] = fact[i-1] * i;
        ifact[n] = fact[n].inv();
        for (int i=n; i>=1; --i) ifact[i-1] = ifact[i] * i;
    }
    mint operator()(int n, int k) {
        if (k<0 || k>n) return 0;
        return (fact[n] * ifact[k] * ifact[n-k]);
    }
} cb((int)(5e5));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        auto calc = [&](int mval) -> mint {
            if (mval < 10) return 1;
            int aval = mval / 10, bval = mval % 10;
            mint rev = 0;
            int id = 0;
            while (id <= aval) {
                rev += cb(aval, id);
                ++id;
            }
            return rev;
        };
        mint res = 0;
        while (n) {
            res += calc(m+n%10);
            n /= 10;
        }
        cout << res << endl;
    }
    return 0;
}
