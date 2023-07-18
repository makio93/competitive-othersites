// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return num ? (num-1) % 9 + 1 : num;
    }
};
