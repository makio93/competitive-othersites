#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

const int INF = (int)(2e9);

int op(int l, int r) { return max(l, r); }
int e() { return 1; }
int mapping(int f, int r) { return max(f, r); }
int composition(int f, int g) { return max(f, g); }
int id() { return 1; }

int op2(int l, int r) { return min(l, r); }
int e2() { return INF; }
int mapping2(int f, int r) { return min(f, r); }
int composition2(int f, int g) { return min(f, g); }
int id2() { return INF; }

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> l(q), r(q), b(q);
    rep(i, q) {
        cin >> l[i] >> r[i] >> b[i];
        l[i]--;
    }
    lazy_segtree<int, op, e, int, mapping, composition, id> lseg1(n+1);
    rep(i, q) lseg1.apply(l[i], r[i], b[i]);
    vector<int> res(n);
    rep(i, n) res[i] = lseg1.get(i);
    lazy_segtree<int, op2, e2, int, mapping2, composition2, id2> lseg2(res);
    bool ok = true;
    rep(i, q) if (lseg2.prod(l[i], r[i]) != b[i]) ok = false;
    if (ok) rep(i, n) printf("%d%c", res[i], (i<n-1?' ':'\n'));
    else cout << -1 << endl;
    return 0;
}
