// 本番WA2

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
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        rep(i, n) cin >> a[i] >> b[i];
        map<int, set<pair<int, int>>> hlst, wlst;
        rep(i, n) {
            hlst[a[i]].emplace(b[i], i);
            wlst[b[i]].emplace(a[i], i);
        }
        ll asum = 0, aval = 0;
        rep(i, n) asum += (ll)a[i] * b[i];
        aval = asum;
        function<bool(int,int,bool)> dfs = [&](int hi, int wi, bool hdir) {
            if (hi<0 || wi<0 || aval<0) return false;
            if (hlst.empty()) {
                if (hdir) return aval == 0 && hi == 0;
                else return aval == 0 && wi == 0;
            }
            else if (hi<=0 || wi<=0 || aval<=0) return false;
            if (hdir) {
                if (hlst.rbegin()->first != hi) return false;
                auto tmp = hlst.rbegin()->second;
                hlst.erase(hlst.rbegin()->first);
                int wsum = 0;
                for (const auto& pi : tmp) {
                    wlst[pi.first].erase({ a[pi.second], pi.second });
                    if (wlst[pi.first].empty()) wlst.erase(pi.first);
                    wsum += pi.first;
                }
                aval -= (ll)wsum * hi;
                bool rval = dfs(hi, wi-wsum, !hdir);
                for (const auto& pi : tmp) wlst[pi.first].emplace(a[pi.second], pi.second);
                hlst[hi] = tmp;
                aval += (ll)wsum * hi;
                return rval;
            }
            else {
                if (wlst.rbegin()->first != wi) return false;
                auto tmp = wlst.rbegin()->second;
                wlst.erase(wlst.rbegin()->first);
                int hsum = 0;
                for (const auto& pi : tmp) {
                    hlst[pi.first].erase({ b[pi.second], pi.second });
                    if (hlst[pi.first].empty()) hlst.erase(pi.first);
                    hsum += pi.first;
                }
                aval -= (ll)hsum * wi;
                bool rval = dfs(hi-hsum, wi, !hdir);
                for (const auto& pi : tmp) hlst[pi.first].emplace(b[pi.second], pi.second);
                wlst[wi] = tmp;
                aval += (ll)hsum * wi;
                return rval;
            }
        };
        ll hs = hlst.rbegin()->first, ws = wlst.rbegin()->first;
        vector<pair<int, int>> res;
        if (asum%hs==0 && dfs(hs, asum/hs, true)) res.emplace_back(hs, asum/hs);
        if (asum%ws==0 && dfs(asum/ws, ws, false) && asum/ws!=hs) res.emplace_back(asum/ws, ws);
        int m = res.size();
        cout << m << endl;
        rep(i, m) cout << res[i].first << ' ' << res[i].second << endl;
    }
    return 0;
}
