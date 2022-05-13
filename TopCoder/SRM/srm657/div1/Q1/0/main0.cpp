// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class ProblemSets {
public:
    ll maxSets(ll E, ll EM, ll M, ll MH, ll H) {
        ll l1 = E, r1 = E + EM, l2 = E+EM+M, r2 = E+EM+M+MH, sum = E+EM+M+MH+H;
        function<ll(ll)> calc = [&](ll id) -> ll {
            ll val = id + (sum-id) / 2;
            val = max(l2, min(r2, val));
            return min({ id, val-id, sum-val });
        };
        ll res = calc(l1);
        while (r1-l1 >= 1) {
            if (r1-l1 < 3) {
                for (ll id=l1; id<=r1; ++id) res = max(res, calc(id));
                break;
            }
            else {
                ll cl = l1 + (r1-l1) / 3, cr = r1 - (r1-l1) / 3;
                res = max({ res, calc(l1), calc(r1), calc(cl), calc(cr) });
                if (calc(cl) < calc(cr)) l1 = cl;
                else if (calc(cl) > calc(cr)) r1 = cr;
                else if (l1 <= r1) l1 = cl;
                else r1 = cr;
            }
        }
        return res;
    }
};
