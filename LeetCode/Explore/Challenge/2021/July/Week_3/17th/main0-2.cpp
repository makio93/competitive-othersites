#include <bits/stdc++.h>
using namespace std;

// 自力解答2,自力AC

class Solution {
    const long long mod = (long long)(1e9) + 7;
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        vector<int> res = { -1, -1 };
        bool zero = true;
        for (int i=0; i<n; ++i) if (arr[i] != 0) zero = false;
        if (zero) res = { 0, n-1 };
        else {
            vector<long long> hash(n+1), two(n+1, 1);
            for (int i=n-1; i>=0; --i) {
                hash[i] = (hash[i+1] + two[n-i-1] * arr[i]) % mod;
                two[n-i] = (two[n-i-1] * 2) % mod;
            }
            int llen = -1, clen = -1;
            for (int i=0; i+2<n; ++i) {
                if (llen == -1) {
                    if (arr[i] == 1) llen = i;
                    else continue;
                }
                long long lval = (hash[0] - hash[i+1] + mod) % mod;
                if (clen < i+1) {
                    for (int j=i+1; j+1<n; ++j) if (arr[j] == 1) {
                        clen = j;
                        break;
                    }
                    if (clen == -1) break;
                }
                int llen2 = i - llen + 1, clen2 = clen + llen2 - 1;
                if (clen2 >= n) break;
                long long cval = (hash[i+1] - hash[clen2+1] + mod) % mod * two[clen2-i] % mod;
                if (lval != cval) continue;
                long long rval = hash[clen2+1] * two[n-i-1] % mod;
                if (cval == rval) {
                    res = { i, clen2+1 };
                    break;
                } 
            }
        }
        return res;
    }
};
