#include <bits/stdc++.h>
using namespace std;

// 自力解答,TLE

class Solution {
    const long long mod = (long long)(1e9) + 7;
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        vector<long long> hash(n+1), two(n+1, 1);
        for (int i=n-1; i>=0; --i) {
            hash[i] = (hash[i+1] + two[n-i-1] * arr[i]) % mod;
            two[n-i] = (two[n-i-1] * 2) % mod;
        }
        vector<int> res = { -1, -1 };
        for (int i=0; i+2<n; ++i) {
            long long lval = (hash[0] - hash[i+1] + mod) % mod;
            bool ok = false;
            for (int j=i+1; j+1<n; ++j) {
                long long cval = (hash[i+1] - hash[j+1] + mod) % mod * two[j-i] % mod;
                if (lval != cval) continue;
                long long rval = hash[j+1] * two[n-i-1] % mod;
                if (cval == rval) {
                    ok = true;
                    res = { i, j+1 };
                    break;
                }
            }
            if (ok) break;
        }
        return res;
    }
};
