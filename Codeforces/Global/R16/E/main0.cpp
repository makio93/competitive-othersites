#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番TLE

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        rep(i, n-1) {
            int ui, vi;
            cin >> ui >> vi;
            --ui; --vi;
            g[ui].push_back(vi);
            g[vi].push_back(ui);
        }
        vector<int> deg(n);
        rep(i, n) deg[i] = g[i].size();
        vector<int> lens;
        unordered_set<int> bids;
        vector<bool> buds(n), sbuds(n);
        rep3(i, 1, n) if (deg[i] == 1) {
            function<int(int,int,int)> dfs = [&](int v, int p, int d) -> int {
                if (d > 1) buds[v] = false;
                if (d == 1) {
                    if (v != 0) buds[v] = true;
                    bool sb = false;
                    for (int ti : g[v]) if (ti == 0) sb = true;
                    if (sb) sbuds[v] = true;
                }
                if (v==0 || (p!=-1&&deg[v]!=2)) return d;
                for (int ti : g[v]) if (ti != p) return dfs(ti, v, d+1);
            };
            int lval = dfs(i, -1, 0);
            if (lval > 0) lens.push_back(lval);
        }
        rep(i, n) if (buds[i] && sbuds[i]) bids.insert(i);
        int ans = 1;
        if ((int)(lens.size()) > 1) {
            int sub = 0;
            for (int li : lens) if (li%2==0 && bids.find(li)==bids.end()) ++sub;
            ans = max(1, (int)(lens.size())-sub-(int)(bids.size())/2);
        }
        cout << ans << endl;
    }
    return 0;
}
