// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        return 2 - (int)equal(s.begin(), s.end(), s.rbegin());
    }
};
