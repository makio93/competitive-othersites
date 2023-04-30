// 解説AC2-2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

struct UnionFind {
    vector<int> d;
    stack<int> vals;
    stack<int*> adds;
    UnionFind(int n=0) : d(n, -1) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        adds.push(&d[x]), vals.push(d[x]);
        adds.push(&d[y]), vals.push(d[y]);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    void rollback() {
        *(adds.top()) = vals.top();
        adds.pop(), vals.pop();
    }
    bool same(int x, int y) { return (find(x) == find(y)); }
    int size(int x) { return -d[find(x)]; }
};
struct SegmentTree {
    int n;
    vector<vector<tuple<int, int, int>>> dat;
    UnionFind *uf;
    SegmentTree() { init(1); }
    SegmentTree(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        uf = new UnionFind(n);
        dat = vector<vector<tuple<int, int, int>>>(2*n-1);
    }
    void add(int a, int b, tuple<int, int, int> tup, int k=0, int l=0, int r=-1) {
        if (r == -1) { r = n; k = 0; l = 0; }
        if (r<=a || b<=l) return;
        if (a<=l && r<=b) {
            dat[k].push_back(tup);
            return;
        }
        add(a, b, tup, k*2+1, l, (l+r)/2);
        add(a, b, tup, k*2+2, (l+r)/2, r);
    }
    ll trav(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) { r = n; k = 0; l = 0; }
        int dlen = uf->vals.size();
        for (auto [ui, vi, si] : dat[k]) if (si == 0) uf->unite(ui, vi);
        ll rval = 0;
        if (l+1 == r) {
            for (auto [ui, vi, si] : dat[k]) if (si == 1) rval += uf->size(ui) * (ll)(uf->size(vi));
        }
        else {
            rval += trav(a, b, k*2+1, l, (l+r)/2);
            rval += trav(a, b, k*2+2, (l+r)/2, r);
        }
        while ((int)(uf->vals.size()) > dlen) uf->rollback();
        return rval;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> ei(n-1);
    rep(i, n-1) {
        int ui, vi, xi;
        cin >> ui >> vi >> xi;
        --ui; --vi; --xi;
        ei[i] = { ui, vi, xi };
    }
    sort(all(ei), [](auto& li, auto& ri) -> bool { return get<2>(li) < get<2>(ri); });
    SegmentTree st(n+2);
    rep(i, n-1) {
        int id = lower_bound(all(ei), ei[i], [](auto& li, auto& ri) -> bool { return get<2>(li) < get<2>(ri); }) - ei.begin();
        st.add(0, id+1, { get<0>(ei[i]), get<1>(ei[i]), 0 });
        st.add(id+1, id+2, { get<0>(ei[i]), get<1>(ei[i]), 1 });
        st.add(id+2, n+1, { get<0>(ei[i]), get<1>(ei[i]), 0 });
    }
    cout << st.trav(0, n+2) << endl;
    return 0;
}
