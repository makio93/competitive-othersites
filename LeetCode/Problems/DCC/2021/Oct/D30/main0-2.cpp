#include <bits/stdc++.h>
using namespace std;

// 自力WA

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

class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.length();
        vector<map<ll, unordered_set<int>>> mlst(n+1);
        vector<unordered_map<int, ll>> llst(n+1);
        pair<int, pair<int, int>> res = { 0, { n, n } };
        for (int i=n-1; i>=0; --i) {
            for (int j=n; j>i; --j) {
                int rlen = j - i;
                if (res.first>3 && rlen<=3) break;
                mint rval;
                if (rlen-1 > 0) rval = mint(llst[rlen-1][i+1]) + mint(s[i]-'a') * mint(26).pow(rlen-1);
                else rval = (int)(s[i]-'a');
                if (mlst[rlen].find(rval.x) != mlst[rlen].end()) res = max(res, { rlen, { i, j } });
                mlst[rlen][rval.x].insert(i);
                llst[rlen][i] = rval.x;
            }
        }
        return s.substr(res.second.first, res.second.second-res.second.first);
    }
};
