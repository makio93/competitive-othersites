#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main(){
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int a, b, c;
        cin >> a >> b >> c;
        ll amin = 1, amax = 1, bmin = 1, bmax = 1, cmin = 1, cmax = 1, ten = 1;
        int mcnt = 0;
        while (mcnt <= 9) {
            if (mcnt == a-1) amin = ten;
            if (mcnt == a) amax = ten;
            if (mcnt == b-1) bmin = ten;
            if (mcnt == b) bmax = ten;
            if (mcnt == c-1) cmin = ten;
            if (mcnt == c) cmax = ten;
            ten *= 10;
            ++mcnt;
        }
        ll aval = 1, bval = 1, cval = 1;
        while (cval < cmin) cval *= 2;
        aval = bval = cval;
        while (aval < amin) aval *= 3;
        while (bval < bmin) bval *= 5;
        cout << aval << ' ' << bval << endl;
    }
    return 0;
}
