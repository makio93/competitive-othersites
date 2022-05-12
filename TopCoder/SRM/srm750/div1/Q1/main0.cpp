// 自力,WA

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
        sort(all(candy));
        ll res = 0;
        rep(i, n) {
            ll sum = 0;
            rep(j, n) sum += candy[j] / candy[i];
            ll cell = (bagSize + sum - 1) / sum;
            res = max(res, candy[i]/cell);
        }
        return res;
    }
};
