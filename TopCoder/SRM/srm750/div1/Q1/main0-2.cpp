// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class IdenticalBags {
public:
    ll makeBags(vector<ll> candy, ll bagSize) {
        int n = candy.size();
        ll li = 0, ri = 0;
        rep(i, n) ri = max(ri, candy[i]);
        ++ri;
        while (ri-li > 1) {
            ll ci = li + (ri-li) / 2, cnt = 0;
            rep(i, n) cnt += candy[i] / ci;
            if (cnt >= bagSize) li = ci;
            else ri = ci;
        }
        return li;
    }
};
