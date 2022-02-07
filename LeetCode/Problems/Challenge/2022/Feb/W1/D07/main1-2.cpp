#include <bits/stdc++.h>
using namespace std;

// 解説AC,SUM

class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for (char ci : s) res -= ci;
        for (char ci : t) res += ci;
        return res;
    }
};
