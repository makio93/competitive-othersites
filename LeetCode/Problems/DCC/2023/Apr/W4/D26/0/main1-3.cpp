// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return num == 0 ? 0 : 1 + (num-1) % 9;
    }
};
