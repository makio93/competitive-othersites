// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return num == 0 ? 0 : num % 9 == 0 ? 9 : num % 9;
    }
};
