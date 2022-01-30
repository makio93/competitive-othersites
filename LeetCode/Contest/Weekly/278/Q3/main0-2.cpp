#include <bits/stdc++.h>
using namespace std;

// 本番WA2

using ll = long long;

const ll mod = (ll)(1.1e9) + 7;

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

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashvalue) {
        int n = s.length();
        vector<mint> hvals(n+1);
        mint r = 1;
        for (int i=0; i<n; ++i) {
            hvals[i+1] = (hvals[i] + (mint)(s[i]-'a'+1)*r);
            r *= power;
        }
        int rid = -1;
        r = 1;
        for (int i=0; i+k<n+1; ++i) {
            mint val1 = (hvals[i+k]-hvals[i]) / r;
            if ((val1.x-(val1/modulo*modulo).x+modulo)%modulo == mint(hashvalue).x) {
                rid = i;
                break;
            }
            r *= power;
        }
        return s.substr(rid, k);
    }
};
