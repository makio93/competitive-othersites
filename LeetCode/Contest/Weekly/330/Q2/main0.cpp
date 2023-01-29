// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int monkeyMove(int n) {
        ll sval = 1, two = 2;
        for (int i=0; i<30; ++i) {
            if (n&(1<<i)) sval = sval * two % mod;
            two = two * two % mod;
        }
        sval = (sval - 2 + mod) % mod;
        return (int)sval;
    }
};
