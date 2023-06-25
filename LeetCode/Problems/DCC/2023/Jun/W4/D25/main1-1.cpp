// 解説AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<unordered_map<int, ll>> memo(n);
        function<ll(int,int)> calc = [&](int vi, int di) {
            if (di < 0) return 0LL;
            if (memo[vi].find(di) != memo[vi].end()) return memo[vi][di];
            ll rval = vi == finish ? 1 : 0;
            for (int ti=0; ti<n; ++ti) if (ti != vi) rval = (rval + calc(ti, di-abs(locations[ti]-locations[vi]))) % mod;
            return memo[vi][di] = rval;
        };
        return (int)calc(start, fuel);
    }
};
