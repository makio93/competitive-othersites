#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
    int t;
    cin >> t;
    rep(i0, t) {
        int c, d;
        cin >> c >> d;
        if (abs(c-d)%2 == 1) cout << -1 << endl;
        else {
            int res = 0;
            if (abs(c-d) > 0) ++res;
            if ((c+d)/2 != 0) ++res;
            cout << res << endl;
        }
    }
    return 0;
}
