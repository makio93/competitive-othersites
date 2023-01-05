// 本番AC

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
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) {
            cin >> a[i];
            a[i]--;
        }
        vector<vector<int>> ids(n);
        rep(i, n) ids[a[i]].push_back(i);
        vector<int> p(n), q(n);
        deque<int> pd, qd;
        bool ok = true;
        rep(i, n) {
            if (ids[i].empty()) {
                pd.push_back(i+1);
                qd.push_back(i+1);
                continue;
            }
            if ((int)(ids[i].size()) > 2) {
                ok = false;
                break;
            }
            if ((int)(ids[i].size()) == 2) {
                if (pd.empty() || qd.empty()) {
                    ok = false;
                    break;
                }
                p[ids[i][0]] = q[ids[i][1]] = i+1;
                p[ids[i][1]] = pd.front(); pd.pop_front();
                q[ids[i][0]] = qd.front(); qd.pop_front();
            }
            if ((int)(ids[i].size()) == 1) p[ids[i][0]] = q[ids[i][0]] = i+1;
        }
        if (ok) {
            cout << "YES" << endl;
            rep(i, n) cout << p[i] << ' ';
            cout << endl;
            rep(i, n) cout << q[i] << ' ';
            cout << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
