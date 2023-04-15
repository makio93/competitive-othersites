// 本番AC

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
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        vector<vector<int>> alst(n+1);
        rep(i, n) {
            if (a[i] >= n) alst[n].push_back(i);
            else alst[a[i]].push_back(i);
        }
        int mval = 0;
        while (mval<=n && !alst[mval].empty()) ++mval;
        if (mval == n) {
            cout << "No" << endl;
            continue;
        }
        if ((int)(alst[mval+1].size()) <= 1) {
            cout << "Yes" << endl;
            continue;
        }
        int li = alst[mval+1].front(), ri = alst[mval+1].back();
        bool ok = true;
        vector<int> acnt(n+1);
        rep3(i, li, ri+1) if (a[i] < mval) {
            acnt[a[i]]++;
            if (acnt[a[i]] >= (int)(alst[a[i]].size())) {
                ok = false;
                break;
            }
        }
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
