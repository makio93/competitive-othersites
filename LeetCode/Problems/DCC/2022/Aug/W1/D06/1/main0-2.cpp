// 学習1回目,自力AC2(ヒント有)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int turns = minutesToTest / minutesToDie, bval = 1, res = 0;
        while (buckets > bval) {
            bval *= turns + 1;
            ++res;
        }
        return res;
    }
};
