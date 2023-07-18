// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int nval = 0;
        while (num >= 10) {
            while (num > 0) {
                nval += num % 10;
                num /= 10;
            }
            swap(nval, num);
        }
        return num;
    }
};
