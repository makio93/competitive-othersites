// 学習1回目,自力TLE2-2

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
    auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
        vector<int> cids;
        for (const int& ti : g[vi]) if (ti != pi) {
            dfs(dfs, ti, vi);
            cids.push_back(ti);
        }
        sort(all(cids), [&](auto& li, auto& ri) -> bool { return slst[li].size() > slst[ri].size(); });
        int m = cids.size();
        if (m == 0) {
            slst[vi].insert(a[vi]);
            return;
        }
        bool ok = true;
        for (const int& si : slst[cids[0]]) if ((si^a[vi]) == 0) {
            ok = false;
            break;
        }
        if (ok) {
            for (const int& si : slst[cids[0]]) slst[vi].insert(si^a[vi]);
            rep3(i, 1, m) {
                for (const int& si : slst[cids[i]]) if ((si^a[vi])==0 || slst[vi].find(si)!=slst[vi].end()) {
                    ok = false;
                    break;
                }
                if (!ok) break;
                for (const int& si : slst[cids[i]]) slst[vi].insert(si^a[vi]);
            }
        }
        if (!ok) {
            ++res;
            slst[vi].clear();
        }
        else slst[vi].insert(a[vi]);
        rep(i, m) slst[cids[i]].clear();
        return;
    };
    dfs(dfs);
    cout << res << endl;
    return 0;
}
