// 本番提出,WA+TLE

#include <bits/stdc++.h>
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

int main() {
    int t0;
    cin >> t0;
    for (int i0=0; i0<t0; ++i0) {
        ll l, r;
        cin >> l >> r;
        mint res = 0;
        unordered_map<int, ll> dig;
        auto comb = [&](ll a, ll b) -> mint {
            mint val = 1;
            for (ll i=a; i>=a-b+1; --i) val *= i;
            for (ll i=1; i<=b; ++i) val /= i;
            return val;
        };
        auto dnum = [&](ll d) -> mint {
            mint val = 1;
            ll dcnt = d;
            for (auto pi : dig) {
                val *= comb(dcnt, pi.second);
                dcnt -= pi.second;
            }
            return val;
        };
        auto dfs = [&](auto dfs, ll d, ll mul, ll sum, int nd) -> void {
            if (d+mul-sum > r) return;
            if (d>0 && mul-sum>=0 && d+mul-sum>=l) {
                res += comb(d+mul-sum, d) * dnum(d);
            }
            for (int di=nd; di<=9; ++di) {
                dig[di]++;
                dfs(dfs, d+1, mul*di, sum+di, nd);
                dig[di]--;
                if (dig[di] == 0) dig.erase(di);
            }
        };
        dfs(dfs, 0, 1, 0, 2);
        cout << res.x << endl;
    }
    return 0;
}
