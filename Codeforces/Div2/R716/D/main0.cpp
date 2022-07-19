// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<unordered_map<int, int>> scnt(n+1);
    rep3(i, 1, n+1) {
        scnt[i] = scnt[i-1];
        scnt[i][a[i-1]]++;
    }
    rep(i, q) {
        int li, ri;
        cin >> li >> ri;
        --li;
        int mval = 0;
        for (auto p : scnt[ri]) {
            if (scnt[li].find(p.first) != scnt[li].end()) {
                mval = max(mval, p.second-scnt[li][p.first]);
            }
            else mval = max(mval, p.second);
        }
        int sub = mval - (ri-li+1) / 2;
        if (sub <= 0) cout << 1 << endl;
        else {
            sub *= 2;
            int res = sub / 3 * 2 + 1;
            sub %= 3;
            if (sub > 0) {
                if ((ri-li)%2 != 0) {
                    if (sub <= 1) ++res;
                    else res += 2; 
                }
                else ++res;
            }
            cout << res << endl;
        }
    }
    return 0;
}
