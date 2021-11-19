#include <bits/stdc++.h>
using namespace std;

// 自力TLE

using ll = long long;
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

static vector<vector<bool>> exist(1001, vector<bool>(1001));
static vector<vector<mint>> memo(1001, vector<mint>(1001));
class Solution {
    mint calc(int n, int k) {
        if (exist[n][k]) return memo[n][k];
        if (k == 0) { exist[n][k] = true; return memo[n][k] = 1; }
        else if (n <= 1) { exist[n][k] = true; return memo[n][k] = 0; }
        else {
            mint res = 0;
            for (int i=0; i<=min(k,n-1); ++i) res += kInversePairs(n-1, k-i);
            exist[n][k] = true;
            return memo[n][k] = res;
        }
    }
public:
    int kInversePairs(int n, int k) {
        return (int)calc(n, k).x;
    }
};
