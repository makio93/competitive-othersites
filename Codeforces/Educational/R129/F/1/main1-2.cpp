// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

struct edge { int v, u, w; };

struct DynamicConnectivity {
    int n;
    vector<int> d, p, val;
    vector<int*> where;
    vector<vector<edge>> t;
    DynamicConnectivity(int n_=0) {
        n = n_;
        d.resize(n, 1);
        p.resize(n, 0);
        iota(all(p), 0);
        t.resize(n*4, vector<edge>());
    }
    int find(int x) {
        if (p[x] == x) return x;
        return find(p[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] < d[y]) swap(x, y);
        where.push_back(&d[x]);
        val.push_back(d[x]);
        d[x] += d[y];
        where.push_back(&p[y]);
        val.push_back(p[y]);
        p[y] = x;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return d[find(x)]; }
    void add(const edge& e, int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        if (a >= b) return;
        if (a==l && b==r) {
            t[k].push_back(e);
            return;
        }
        int m = (l+r) / 2;
        add(e, a, min(m, b), k*2+1, l, m);
        add(e, max(m, a), b, k*2+2, m, r);
    }
    void rollback() {
        *where.back() = val.back();
        where.pop_back();
        val.pop_back();
    }
    ll trav(int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        int slen = where.size();
        for (auto& ei : t[k]) if (ei.w == 0) unite(ei.u, ei.v);
        ll rval = 0;
        if (r-l == 1) {
            for (auto& ei : t[k]) if (ei.w == 1) rval += (ll)d[find(ei.u)] * d[find(ei.v)];
        }
        else {
            int m = (l+r) / 2;
            rval += trav(k*2+1, l, m);
            rval += trav(k*2+2, m, r);
        }
        while ((int)(where.size()) > slen) rollback();
        return rval;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<edge> e(n-1);
    rep(i, n-1) {
        cin >> e[i].v >> e[i].u >> e[i].w;
        e[i].v--; e[i].u--; e[i].w--;
    }
    sort(all(e), [](const edge& li, const edge& ri) -> bool { return li.w < ri.w; });
    DynamicConnectivity dc(n);
    rep(i, n-1) {
        int id = lower_bound(all(e), e[i], [](const edge& li, const edge& ri) -> bool {
            return li.w < ri.w;
        }) - e.begin();
        dc.add({ e[i].u, e[i].v, 0 }, 0, id);
        dc.add({ e[i].u, e[i].v, 1 }, id, id+1);
        dc.add({ e[i].u, e[i].v, 0 }, id+1, n);
    }
    ll res = dc.trav();
    cout << res << endl;
    return 0;
}
