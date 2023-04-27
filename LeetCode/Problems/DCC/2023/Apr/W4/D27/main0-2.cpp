// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int res = 0;
        for (int i=1; i*i<=n; ++i) res = i;
        return res;
    }
};
