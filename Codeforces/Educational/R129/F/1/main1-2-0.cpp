// 学習1回目,解法2-0,AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

struct UnionFindUndo {
    vector<int> data;
    stack<pair<int, int>> history;
    UnionFindUndo(int n) { data.assign(n, -1); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        history.emplace(x, data[x]);
        history.emplace(y, data[y]);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
    int find(int k) {
        if (data[k] < 0) return (k);
        return find(data[k]);
    }
    int size(int k) { return -data[find(k)]; }
    void undo() {
        data[history.top().first] = history.top().second;
        history.pop();
        data[history.top().first] = history.top().second;
        history.pop();
    }
    void snapshot() { while (history.size()) history.pop(); }
    void rollback() { while (history.size()) undo(); }
};

struct OfflineDynamicConnectivity {
    UnionFindUndo uf;
    int V, Q, segsz, comp;
    vector<vector<pair<int, int>>> seg;
    vector<pair<pair<int, int>, pair<int, int>>> pend;
    map<pair<int, int>, int> cnt, appear;
    OfflineDynamicConnectivity(int V, int Q) : uf(V), V(V), Q(Q), comp(V) {
        segsz = 1;
        while (segsz < Q) segsz <<= 1;
        seg.resize(2 * segsz - 1);
    }
    void insert(int idx, int s, int t) {
        auto e = minmax(s, t);
        if (cnt[e]++ == 0) appear[e] = idx;
    }
    void erase(int idx, int s, int t) {
        auto e = minmax(s, t);
        if (--cnt[e] == 0) pend.emplace_back(make_pair(appear[e], idx), e);
    }
    void add(int a, int b, const pair<int, int> &e, int k, int l, int r) {
        if (r<=a || b<=l) return;
        if (a<=l && r<=b) {
            seg[k].emplace_back(e);
            return;
        }
        add(a, b, e, 2*k+1, l, (l+r)>>1);
        add(a, b, e, 2*k+2, (l+r)>>1, r);
    }
    void add(int a, int b, const pair<int, int> &e) { add(a, b, e, 0, 0, segsz); }
    void build() {
        for (auto &p : cnt) if (p.second > 0) pend.emplace_back(make_pair(appear[p.first], Q), p.first);
        for (auto &s : pend) add(s.first.first, s.first.second, s.second);
    }
    void run(const function<void(int)> &f, int k=0) {
        int add = 0;
        for (auto &e : seg[k]) add += uf.unite(e.first, e.second);
        comp -= add;
        if (k < segsz-1) {
            run(f, 2*k+1);
            run(f, 2*k+2);
        }
        else if(k-(segsz-1) < Q) {
            int query_index = k - (segsz-1);
            f(query_index);
        }
        rep(i, seg[k].size()) uf.undo();
        comp += add;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> xlst(n);
    OfflineDynamicConnectivity dc(n, (n-1)*3);
    rep(i, n-1) {
        int vi, ui, xi;
        cin >> vi >> ui >> xi;
        --vi; --ui; --xi;
        xlst[xi].emplace_back(vi, ui);
        dc.insert(i, vi, ui);
    }
    int id = n-1;
    unordered_map<int, int> sids;
    rep(i, n) if (!xlst[i].empty()) {
        int len = xlst[i].size();
        rep(j, len) dc.erase(id+j, xlst[i][j].first, xlst[i][j].second);
        sids[id+len-1] = i;
        rep(j, len) dc.insert(id+len+j, xlst[i][j].first, xlst[i][j].second);
        id += len * 2;
    }
    dc.build();
    ll res = 0;
    dc.run([&](int kid) {
        if (sids.find(kid) != sids.end()) {
            int sid = sids[kid], len = xlst[sid].size();
            rep(i, len) res += (ll)dc.uf.size(xlst[sid][i].first) * dc.uf.size(xlst[sid][i].second);
        }
    });
    cout << res << endl;
    return 0;
}
