// 学習1回目,自力TLE2

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
    auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> set<int> {
        vector<set<int>> slst;
        for (const int& ti : g[vi]) if (ti != pi) slst.push_back(dfs(dfs, ti, vi));
        sort(all(slst), [](auto& ls, auto& rs) -> bool { return ls.size() > rs.size(); });
        int m = slst.size();
        if (m == 0) return set<int>({ a[vi] });
        bool ok = true;
        set<int> rst;
        for (const int& si : slst[0]) if ((si^a[vi]) == 0) {
            ok = false;
            break;
        }
        for (const int& si : slst[0]) rst.insert(si^a[vi]);
        if (ok) {
            rep3r(i, 1, m) {
                for (const int& si : slst[i]) if ((si^a[vi])==0 || rst.find(si)!=rst.end()) {
                    ok = false;
                    break;
                }
                if (!ok) break;
                for (const int& si : slst[i]) rst.insert(si^a[vi]);
            }
        }
        if (!ok) {
            ++res;
            return set<int>({});
        }
        rst.insert(a[vi]);
        return rst;
    };
    dfs(dfs);
    cout << res << endl;
    return 0;
}
