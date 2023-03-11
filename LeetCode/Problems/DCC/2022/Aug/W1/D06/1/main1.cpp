// 学習1回目,解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int res = 0, rval = minutesToTest / minutesToDie + 1, tval = 1;
        while (tval < buckets) {
            tval *= rval;
            ++res;
        }
        return res;
    }
};
