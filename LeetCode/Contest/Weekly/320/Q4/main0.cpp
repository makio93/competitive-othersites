// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
const vector<char> primes = { '2', '3', '5', '7' };
class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.length();
        vector<vector<ll>> lsums(n+1, vector<ll>(k));
        vector<ll> rcnts(k+1), ncnts;
        rcnts[0] = 1;
        for (int i=0; i<n; ++i) {
            ncnts.assign(k+1, 0);
            for (int j=0; j<k; ++j) lsums[i+1][j] = (lsums[i+1][j] + lsums[i][j]) % mod;
            if (find(primes.begin(), primes.end(), s[i]) != primes.end()) {
                for (int j=0; j<k; ++j) lsums[i+1][j] = (lsums[i+1][j] + rcnts[j]) % mod;
            }
            else {
                for (int j=0; j<k; ++j) if (i+1-minLength+1 >= 0) ncnts[j+1] = lsums[i+1-minLength+1][j];
            }
            swap(ncnts, rcnts);
        }
        return (int)rcnts[k];
    }
};
