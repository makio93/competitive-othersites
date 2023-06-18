// 学習2回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1.5e9);

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
        map<int, int> mp;
        mp[0] = 0;
        rep3(i, 1, n) {
            if (a[mp.rbegin()->first] > a[i]) mp[i] = i;
            else mp.rbegin()->second = i;
        }
        vector<int> res(m);
        rep(i, m) {
            int ki, di;
            cin >> ki >> di;
            --ki;
            auto itr = prev(mp.upper_bound(ki));
            if (itr->first != ki) {
                if (a[itr->first] > a[ki]-di) {
                    int tmp = itr->second;
                    itr->second = ki - 1;
                    mp[ki] = tmp;
                    itr = mp.find(ki);
                }
            }
            a[ki] -= di;
            while (next(itr) != mp.end() && a[ki] <= a[next(itr)->first]) {
                itr->second = next(itr)->second;
                mp.erase(next(itr)->first);
            }
            res[i] = (int)(mp.size());
        }
        rep(i, m) cout << res[i] << ' ';
        cout << endl;
    }
    return 0;
}
