#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC-2,XOR距離を用いる

const vector<string> tar = { "crewmate", "imposter" };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> g(n);
        rep(i, m) {
            int ai, bi;
            string cs;
            cin >> ai >> bi >> cs;
            --ai; --bi;
            rep(j, 2) if (cs == tar[j]) {
                g[ai].emplace_back(bi, j);
                g[bi].emplace_back(ai, j);
            }
        }
        vector<int> colors(n, -1);
        int res = 0;
        bool ok = true;
        rep(i, n) if (colors[i] == -1) {
            vector<int> ccnt(2);
            function<bool(int)> dfs = [&](int v) -> bool {
                ccnt[colors[v]]++;
                for (auto tp : g[v]) {
                    int ncol = colors[v] ^ tp.second;
                    if (colors[tp.first] == -1) {
                        colors[tp.first] = ncol;
                        if (!dfs(tp.first)) return false;
                    }
                    else {
                        if (colors[tp.first] != ncol) return false;
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
