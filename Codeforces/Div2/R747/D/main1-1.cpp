#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC-1,フェイク頂点を用いる

const vector<string> tar = { "crewmate", "imposter" };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n+m);
        rep(i, m) {
            int ai, bi;
            string cs;
            cin >> ai >> bi >> cs;
            --ai; --bi;
            if (cs == tar[1]) {
                g[ai].push_back(bi);
                g[bi].push_back(ai);
            }
            else {
                g[ai].push_back(n+i);
                g[n+i].push_back(ai);
                g[bi].push_back(n+i);
                g[n+i].push_back(bi);
            }
        }
        vector<int> colors(n+m, -1);
        int res = 0;
        bool ok = true;
        rep(i, n) if (colors[i] == -1) {
            vector<int> ccnt(2);
            function<bool(int)> dfs = [&](int v) -> bool {
                if (v < n) ccnt[colors[v]]++;
                int ncol = 1 - colors[v];
                for (int ti : g[v]) {
                    if (colors[ti] == -1) {
                        colors[ti] = ncol;
                        if (!dfs(ti)) return false;
                    }
                    else {
                        if (colors[ti] != ncol) return false;
                    }
                }
                return true;
            };
            colors[i] = 0;
            if (!dfs(i)) {
                ok = false;
                break;
            }
            res += max(ccnt[0], ccnt[1]);
        }
        if (!ok) cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}
