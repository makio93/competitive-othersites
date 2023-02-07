#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int addDigits(int num) {
        string str = to_string(num);
        while (str.length() > 1U) {
            int nval = 0;
            for (char ci : str) nval += ci - '0';
            str = to_string(nval);
        }
        return stoi(str);
    }
};
