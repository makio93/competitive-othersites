#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int s, n;
        cin >> s >> n;
        if (n == 1) cout << s << endl;
        else {
            int fval = s - (n-1);
            if (fval >= 10) fval = fval / 10 * 10;
            int rval = s - fval, sval = rval - (n-2), tval = 1;
            if (n>=3 && sval%10!=0) {
                if (fval/100>=1 && fval%100/10>=1) {
                    fval -= 10;
                    int sadd = (10-sval%10);
                    sval += sadd;
                    tval += 10 - sadd;
                }
            }
            vector<int> a;
            a.push_back(fval);
            a.push_back(sval);
            if (n >= 3) {
                a.push_back(tval);
                rep(i, n-3) a.push_back(1);
            }
            else rep(i, n-2) a.push_back(1);
            rep(i, n) printf("%d%c", a[i], (i<n-1?' ':'\n'));
        }
    }
    return 0;
}
