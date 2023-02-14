// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

struct LazySeg {
    int l, r, val, tag;
    LazySeg *lch, *rch;
    bool is_lazy;
    LazySeg(int l_, int r_) {
        l = l_; r = r_;
        val = tag = 0;
        lch = rch = NULL;
        is_lazy = false;
        if (r-l > 1) {
            int m = (l+r) / 2;
            lch = new LazySeg(l, m);
            rch = new LazySeg(m, r);
        }
    }
    void unlazy() {
        if (!is_lazy) return;
        val = (r-l) * tag;
        if (r-l > 1) {
            lch->is_lazy = rch->is_lazy = true;
            lch->tag = rch->tag = tag;
        }
        is_lazy = false;
    }
    void update(int a, int b, int x) {
        unlazy();
        if (a>=r || b<=l) return;
        if (a<=l && b>=r) {
            tag = x;
            is_lazy = true;
            unlazy();
        }
        else {
            lch->update(a, b, x);
            rch->update(a, b, x);
            val = lch->val + rch->val;
        }
    }
    int query(int a, int b) {
        unlazy();
        if (a>=r || b<=l) return 0;
        if (a<=l && b>=r) return val;
        else return lch->query(a, b) + rch->query(a, b);
    }
    int search(int id, int pre, int x) {
        unlazy();
        if (r-l == 1) {
            if (val == x) return l;
            else return l-1;
        }
        int m = (l + r) / 2;
        lch->unlazy();
        if (id >= m) return rch->search(id, pre-lch->val, x);
        else if (lch->val-pre == (m-id)*x) return rch->search(m, 0, x);
        else return lch->search(id, pre, x);
    }
    int get_max() {
        unlazy();
        if (r-l == 1) {
            if (val == 1) return l;
            else return l-1;
        }
        rch->unlazy();
        if (rch->val > 0) return rch->get_max();
        else return lch->get_max();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), k(q), l(q);
    rep(i, n) cin >> a[i];
    rep(i, q) {
        cin >> k[i] >> l[i];
        k[i]--;
    }
    int mval = max(*max_element(all(a)), *max_element(all(l))) + 20;
    LazySeg ab(0, mval+1);
    auto add = [&](int id) -> void {
        int x = ab.search(id, ab.query(0, id), 1) + 1;
        ab.update(x, x+1, 1);
        if (x > id) ab.update(id, x, 0);
    };
    auto del = [&](int id) -> void {
        int x = ab.search(id, ab.query(0, id), 0) + 1;
        ab.update(x, x+1, 0);
        if (x > id) ab.update(id, x, 1);
    };
    rep(i, n) add(a[i]);
    rep(i, q) {
        del(a[k[i]]);
        a[k[i]] = l[i];
        add(a[k[i]]);
        cout << ab.get_max() << endl;
    }
    return 0;
}
