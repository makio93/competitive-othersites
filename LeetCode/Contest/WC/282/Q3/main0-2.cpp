// バチャ本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long lval = 0, rval = (long long)(1.1e14);
        while (rval-lval > 1) {
            long long cval = lval + (rval-lval) / 2, tcnt = 0;
            for (int i=0; i<n; ++i) tcnt += cval / time[i];
            if (tcnt >= (long long)totalTrips) rval = cval;
            else lval = cval;
        }
        return rval;
    }
};
