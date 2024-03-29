// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        while (n > 0) {
            if ((n&3) == 3) {
                ++res;
                ++n;
            }
            else {
                res += n & 1;
                n >>= 1;
            }
        }
        return res;
    }
};
