// 解説AC2-2

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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        vector<pair<int, int>> atmp(n);
        rep(i, n) atmp[i] = { a[i], i };
        sort(all(atmp));
        rep(i, k-1) a[atmp[i].second] = INF;
        set<pair<int, int>> ast;
        rep(i, n) ast.emplace(a[i], i);
        int res = 0;
        rep(i, n) {
            auto neighbor = [&](int id) -> int {
                if (id-1 < 0) return min(a[id], a[id+1]);
                else if (id+1 >= n) return min(a[id], a[id-1]);
                else return max(min(a[id], a[id+1]), min(a[id], a[id-1]));
            };
            auto check = [&](int cid, int tid) -> int {
                pair<int, int> tmp = { a[tid], tid };
                ast.erase(tmp);
                ast.emplace(INF, tid);
                a[tid] = INF;
                int rval = min({ INF, ast.begin()->first*2, neighbor(cid) });
                ast.erase({ INF, tid });
                ast.insert(tmp);
                a[tid] = tmp.first;
                return rval;
            };
            res = max({ res, check(i, i), check(i, ast.begin()->second) });
        }
        cout << res << endl;
    }
    return 0;
}
