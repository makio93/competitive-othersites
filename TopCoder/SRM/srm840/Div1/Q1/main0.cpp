// 本番AC

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
struct UnionFind {
    vector<int> d;
    UnionFind(int n=0) : d(n, -1) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return (d[x] = find(d[x]));
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return (find(x) == find(y)); }
    int size(int x) { return -d[find(x)]; }
};
class Postcards {
public:
    int count(int n, int y, int seed) {
        ll state = seed;
        vector<int> a(y), b(y);
        rep(i, y) {
            state = (state * 1103515245LL + 12345) % (1LL<<31);
            a[i] = state % n;
            state = (state * 1103515245LL + 12345) % (1LL<<31);
            b[i] = state % n;
        }
        vector<int> ids;
        rep(i, y) ids.push_back(a[i]);
        rep(i, y) ids.push_back(b[i]);
        sort(all(ids));
        ids.erase(unique(all(ids)), ids.end());
        int m = ids.size();
        map<int, int> rids;
        rep(i, m) rids[ids[i]] = i;
        mint res = (mint(n) * (n+1) * (2*n+1) / 6 - mint(n) * (n+1) / 2) * y;
        UnionFind uf(m);
        vector<mint> gsize(m);
        rep(i, m) gsize[i] = ids[i] + 1;
        rep(i, y) {
            if (uf.same(rids[a[i]], rids[b[i]])) continue;
            mint al = gsize[uf.find(rids[a[i]])], bl = gsize[uf.find(rids[b[i]])];
            res += al * bl * 2 * (y-i);
            uf.unite(rids[a[i]], rids[b[i]]);
            gsize[uf.find(rids[a[i]])] = al + bl;
        }
        return res.x;
    }
};
