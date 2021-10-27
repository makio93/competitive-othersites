// 本番AC

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll mod = 998244353LL;

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
        fact[0] = 1;
        for (int i=1; i<=n; ++i) fact[i] = fact[i-1] * i;
        ifact[n] = fact[n].inv();
        for (int i=n; i>=1; --i) ifact[i-1] = ifact[i] * i;
    }
    mint operator()(int n, int k) {
        if (k<0 || k>n) return 0;
        return (fact[n] * ifact[k] * ifact[n-k]);
    }
};

int main() {
    int t0;
    cin >> t0;
    combination cb((int)(3e5)+5);
    for (int i0=0; i0<t0; ++i0) {
        int n, k;
        cin >> n >> k;
        mint res = cb(n+k, n+1) * mint(n) * (n+1) / 2;
        cout << res << endl;
    }
    return 0;
}
