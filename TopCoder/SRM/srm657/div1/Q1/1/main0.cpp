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
        ll sum = E+EM+M+MH+H;
        ll li = 0, ri = sum;
        while (ri-li > 1) {
            ll ci = li + (ri-li) / 2;
            if (ci<=E+EM && ci<=MH+H && ci<=sum-max(E,ci)-max(H,ci)) li = ci;
            else ri = ci;
        }
        return li;
    }
};
