// 学習1回目,自力TLE1

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
        set<int> st, tar;
        bool ok = true;
        for (const int& ti : g[vi]) if (ti != pi) {
            auto cst = dfs(dfs, ti, vi);
            for (const int& si : cst) if ((si^a[vi])==0 || tar.find(si^a[vi])!=tar.end()) ok = false;
            for (const int& si : cst) tar.insert(si);
        }
        if (!ok) {
            ++res;
            return st;
        }
        for (const int& si : tar) st.insert(si^a[vi]);
        st.insert(a[vi]);
        return st;
    };
    dfs(dfs);
    cout << res << endl;
    return 0;
}
