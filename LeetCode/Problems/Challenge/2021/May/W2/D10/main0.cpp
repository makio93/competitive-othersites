#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> vals(n);
        for (int i=2; i<n; ++i) {
            if (vals[i]) continue;
            ++res;
            for (int j=i; j<n; j+=i) vals[j] = true;
        }
        return res;
    }
};
