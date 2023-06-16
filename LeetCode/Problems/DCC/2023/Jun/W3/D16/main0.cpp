// 自力AC

#include <bits/stdc++.h>
using namespace std;

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
};
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        combination cb(n+5);
        function<mint(vector<int>&)> calc = [&calc,&cb](vector<int>& vlst) {
            if (vlst.empty()) return mint(1);
            int m = vlst.size();
            vector<int> llst, rlst;
            for (int i=1; i<m; ++i) {
                if (vlst[i] < vlst[0]) llst.push_back(vlst[i]);
                else rlst.push_back(vlst[i]);
            }
            mint rval = calc(llst) * calc(rlst) * cb((int)(llst.size())+(int)(rlst.size()), (int)(llst.size()));
            return rval;
        };
        return (int)(calc(nums)-1).x;
    }
};
