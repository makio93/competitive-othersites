#include <bits/stdc++.h>
using namespace std;

// 本番AC

using ll = long long;
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        ll sum = 0;
        for (int i=0; i<m; ++i) sum += quantities[i];
        ll lval = 0, rval = sum;
        while (rval-lval > 1) {
            ll cval = lval + (rval-lval) / 2;
            ll cnt = 0;
            for (int i=0; i<m; ++i) cnt += (quantities[i]+cval-1) / cval;
            if (cnt <= (ll)n) rval = cval;
            else lval = cval;
        }
        return (int)rval;
    }
};
