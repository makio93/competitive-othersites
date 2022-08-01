// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        int res = 1;
        for (int i=0; i<4; ++i) res = res * (n+4-i) / (i+1);
        return res;
    }
};
