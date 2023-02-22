// 学習1回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int res = 0;
    vector<set<int>> slst(n);
    auto dfs = [&](auto dfs, int pval=0, int vi=0, int pi=-1) -> void {
        int vval = pval ^ a[vi];
        slst[vi].insert(vval);
        bool bad = false;
        for (const int& ti : g[vi]) if (ti != pi) {
            dfs(dfs, vval, ti, vi);
            if (slst[ti].size() > slst[vi].size()) swap(slst[ti], slst[vi]);
            for (const int& tval : slst[ti]) bad |= slst[vi].find(tval^a[vi]) != slst[vi].end();
            for (const int& tval : slst[ti]) slst[vi].insert(tval);
            slst[ti].clear();
        }
        if (bad) {
            ++res;
            slst[vi].clear();
        }
    };
    dfs(dfs);
    cout << res << endl;
    return 0;
}
