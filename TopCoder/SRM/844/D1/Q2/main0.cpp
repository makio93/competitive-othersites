// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class Presents2023 {
    ll sq2(ll val) {
        if (val <= 1) return val;
        ll lval = 0, rval = val;
        while (rval-lval > 1) {
            ll cval = lval + (rval-lval) / 2;
            if (cval <= val/cval) lval = cval;
            else rval = cval;
        }
        return lval;
    }
public:
    ll pack(ll paperArea) {
        ll res = 0;
        while (paperArea >= 6) {
            ll sval = sq2(paperArea/6);
            if (sval*(sval+1)*4+(sval+1)*(sval+1)*2 <= paperArea) {
                res += sval * (sval+1) * (sval+1);
                paperArea -= sval*(sval+1)*4+(sval+1)*(sval+1)*2;
            }
            else if (sval*(sval+1)*4+sval*sval*2 <= paperArea) {
                ll tval = (paperArea - sval * sval * 2) / 4 / sval;
                res += sval * sval * tval;
                paperArea -= sval*tval*4+sval*sval*2;
            }
            else {
                res += sval * sval * sval;
                paperArea -= sval*sval*6;
            }
        }
        return res;
    }
};
