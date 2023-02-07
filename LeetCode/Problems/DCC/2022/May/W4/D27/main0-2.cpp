// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        while (num > 1) {
            if (num&1) ++res;
            num >>= 1;
            ++res;
        }
        return res + num;
    }
};
