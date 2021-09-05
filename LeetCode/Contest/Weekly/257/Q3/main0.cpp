#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
    const long long mod = (long long)(1e9) + 7;
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<long long> fval(n);
        fval[0] = 1;
        for (int i=0; i<n-1; ++i) fval[i+1] = (fval[i+1] + fval[i] + (fval[i] - fval[nextVisit[i]] + 2 + mod)) % mod;
        return (int)((fval[n-1] + mod - 1) % mod);
    }
};
