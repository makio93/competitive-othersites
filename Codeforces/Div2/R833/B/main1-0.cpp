// 解説AC0

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
        string s;
        cin >> n >> s;
        int res = 0;
        rep(i, n) {
            vector<int> ccnt(10);
            rep(j, 100) {
                if (i+j >= n) break;
                ccnt[s[i+j]-'0']++;
                int mval = 0, tcnt = 0;
                rep(i2, 10) {
                    if (ccnt[i2] > 0) ++tcnt;
                    mval = max(mval, ccnt[i2]);
                }
                if (mval > 10) break;
                if (mval <= tcnt) ++res;
            }
        }
        cout << res << endl;
    }
    return 0;
}
