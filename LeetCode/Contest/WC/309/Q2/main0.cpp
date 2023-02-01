// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
    ll modpow(ll a, ll b) {
        ll p = 1, q = a;
        for (int i=0; i<63; ++i) {
            if (b & (1LL<<i)) p = p * q % mod;
            q = q * q % mod;
        }
        return p;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        if (startPos > endPos) swap(startPos, endPos);
        if (endPos-startPos>k || (startPos+k-endPos)%2==1) return 0;
        int r = (startPos+k-endPos) / 2;
        if (k-r < r) r = k-r;
        ll res = 1;
        for (int i=0; i<r; ++i) {
            res = res * (k-i) % mod;
            res = res * modpow(i+1, mod-2) % mod;
        }
        return (int)res;
    }
};
