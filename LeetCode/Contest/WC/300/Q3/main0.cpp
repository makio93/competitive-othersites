// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> add(n+1), sub(n+1);
        ll res = 0;
        add[0] = sub[min(n,forget)] = 1;
        for (int i=0; i<n; ++i) {
            res = (res + add[i] - sub[i] + mod) % mod;
            for (int j=i+delay; j<=min(n,i+forget-1); ++j) {
                add[j] = (add[j] + add[i]) % mod;
                sub[min(n,j+forget)] = (sub[min(n,j+forget)] + add[i]) % mod;
            }
        }
        return (int)res;
    }
};
