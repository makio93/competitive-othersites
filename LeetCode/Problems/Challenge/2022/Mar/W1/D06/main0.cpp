// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int countOrders(int n) {
        if (n == 1) return 1;
        else {
            ll rval = countOrders(n-1);
            return (int)((n*2) * (n*2-1) / 2 * rval % mod);
        }
    }
};
