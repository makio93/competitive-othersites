#include <bits/stdc++.h>
using namespace std;

// 解説AC,XOR

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (char ci : s) res ^= ci;
        for (char ci : t) res ^= ci;
        return res;
    }
};
