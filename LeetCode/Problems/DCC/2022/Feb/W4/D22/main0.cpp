// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length(), res = 0;
        for (int i=0; i<n; ++i) {
            res *= 26;
            res += columnTitle[i] - 'A' + 1;
        }
        return res;
    }
};
