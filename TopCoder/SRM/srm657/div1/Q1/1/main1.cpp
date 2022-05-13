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
        ll li = 0, ri = E+EM+M+MH+H;
        while (ri-li > 1) {
            ll ci = li + (ri-li) / 2;
            auto check = [&](ll val) -> bool {
                if (E+EM<val || MH+H<val) return false;
                ll am = min(EM, E+EM-val), bm = min(MH, MH+H-val);
                return (M+am+bm >= val);
            };
            if (check(ci)) li = ci;
            else ri = ci;
        }
        return li;
    }
};
