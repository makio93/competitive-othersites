#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    int countPrimes(int n) {
        if (n == 0) return 0;
        vector<bool> vals(n, true);
        vals[0] = vals[1] = false;
        for (int i=2; i*i<n; ++i) {
            if (!vals[i]) continue;
            for (int j=i*i; j<n; j+=i) vals[j] = false;
        }
        return count(vals.begin(), vals.end(), true);
    }
};
