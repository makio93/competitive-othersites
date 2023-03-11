// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int choose(int a, int b, int lim) {
        if (b > a) return 0;
        if (a-b < b) return choose(a, a-b, lim);
        int rval = 1;
        for (int i=0; i<b; ++i) rval = min(rval*(a-i)/(i+1), lim);
        return rval;
    }
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets == 1) return 0;
        int term = minutesToTest / minutesToDie;
        vector<vector<int>> memo(buckets+1, vector<int>(term+1, -1));
        int li = 0, ri = buckets;
        auto calc = [&](auto calc, int di, int ri) -> int {
            if (memo[di][ri] != -1) return memo[di][ri];
            if (ri == 0) return memo[di][ri] = 1;
            else if (ri == 1) {
                int rval = 1;
                for (int i=0; i<di; ++i) {
                    if (rval > buckets) break;
                    rval *= 2;
                }
                rval = min(rval, buckets);
                return memo[di][ri] = rval;
            }
            else if (di == 1) return memo[di][ri] = ri + 1;
            else {
                int rval = 0;
                for (int i=0; i<=di; ++i) rval = min(rval+choose(di,i,buckets)*calc(calc,di-i,ri-1), buckets);
                return memo[di][ri] = rval;
            }
        };
        while (ri-li > 1) {
            int ci = ri - (ri-li) / 2;
            if (calc(calc, ci, term) >= buckets) ri = ci;
            else li = ci;
        }
        return ri;
    }
};
