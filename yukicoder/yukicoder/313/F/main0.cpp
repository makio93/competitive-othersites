#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

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

inline int mex(int a, int b) {
    int res = 0;
    while (res==a || res==b) ++res;
    return res;
}

string s;

map<pair<int, int>, pair<mint, int>> memo;
pair<mint, int> calc(int id, int k) {
    if (memo.find({id,k}) != memo.end()) return memo[{id,k}];
    pair<mint, int> res = { mint(0), id };
    if (id >= (int)(s.length())) return (memo[{id,k}] = res);
    if (s[id] == 'm') {
        int nid1 = id + 4;
        pair<mint, int> rzero1 = { mint(0), id }, rzero2 = { mint(0), id };
        rzero1 = calc(nid1, 0);
        int nid2 = rzero1.second + 2;
        rzero2 = calc(nid2, 0);
        res.second = rzero2.second + 1;
        if (s[id+1]=='a' || s[id+1]=='?') rep(i, 3) rep(j, 3) if (max(i, j) == k) res.first += calc(nid1, i).first * calc(nid2, j).first;
        if (s[id+1]=='e' || s[id+1]=='?') rep(i, 3) rep(j, 3) if (mex(i, j) == k) res.first += calc(nid1, i).first * calc(nid2, j).first;
    }
    else {
        if (s[id] == '?') res.first = 1;
        else if (s[id]-'0' == k) res.first = 1;
        else res.first = 0;
    }
    return (memo[{id,k}] = res);
}

int main() {
    int k;
    cin >> s >> k;
    cout << calc(0, k).first << endl;
    return 0;
}
