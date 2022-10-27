// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        map<int, int> alst;
        alst[0] = a[0];
        rep3(i, 1, n) if (a[i] < alst.rbegin()->second) alst[i] = a[i];
        rep(i, m) {
            int ki, di;
            cin >> ki >> di;
            --ki;
            if (di > 0) {
                auto itr = prev(alst.upper_bound(ki));
                a[ki] -= di;
                if (ki == itr->first) itr->second = a[ki];
                else if (a[ki] < itr->second) {
                    alst[ki] = a[ki];
                    itr = alst.find(ki);
                }
                while (next(itr) != alst.end()) {
                    if (next(itr)->second < itr->second) break;
                    alst.erase(next(itr));
                }
            }
            cout << (int)(alst.size()) << ' ';
        }
        cout << endl;
    }
    return 0;
}
