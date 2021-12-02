#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

ll mod;

struct mint {
    ll x;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
    int n;
    cin >> n;
    mod = n;
    set<int> res;
    mint val = 1;
    res.insert(1);
    rep3(i, 2, n) {
        if (gcd(n,i) == 1) {
            val *= i;
            res.insert(i);
        }
    }
    if (val.x != 1) {
            mint rval = mint(1) / val;
            rep3r(i, 2, n) if (res.find(i) != res.end()) {
                if (rval.x == mint(i).x) {
                    res.erase(i);
                    break;
                }
            }
    }
    int len = res.size(), id = 0;
    cout << len << endl;
    for (auto itr=res.begin(); itr!=res.end(); ++itr,++id) printf("%d%c", (*itr), (id<len-1?' ':'\n'));
    return 0;
}
