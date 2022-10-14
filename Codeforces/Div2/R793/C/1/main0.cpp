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
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        map<int, int> acnt;
        rep(i, n) acnt[a[i]]++;
        vector<int> ccnt(2);
        for (const auto& pi : acnt) {
            if (pi.second >= 2) ccnt[1]++;
            else ccnt[0]++;
        }
        int res = ccnt[1] + (ccnt[0]+1) / 2;
        cout << res << endl;
    }
    return 0;
}
