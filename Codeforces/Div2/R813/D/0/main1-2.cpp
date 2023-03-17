// 解説AC2

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
        multiset<int> ast;
        rep(i, n-1) ast.insert(min(a[i], a[i+1]));
        int res = 0;
        rep(i, n) {
            int aval = a[i];
            a[i] = INF;
            if (i-1 >= 0) {
                ast.erase(ast.lower_bound(min(a[i-1], aval)));
                ast.insert(min(a[i-1], a[i]));
            }
            if (i+1 < n) {
                ast.erase(ast.lower_bound(min(aval, a[i+1])));
                ast.insert(min(a[i], a[i+1]));
            }
            res = max({ res, min({ INF, *ast.begin()*2, *ast.rbegin() })});
            if (i-1 >= 0) {
                ast.erase(ast.lower_bound(min(a[i-1], a[i])));
                ast.insert(min(a[i-1], aval));
            }
            if (i+1 < n) {
                ast.erase(ast.lower_bound(min(a[i], a[i+1])));
                ast.insert(min(aval, a[i+1]));
            }
            a[i] = aval;
        }
        cout << res << endl;
    }
    return 0;
}
