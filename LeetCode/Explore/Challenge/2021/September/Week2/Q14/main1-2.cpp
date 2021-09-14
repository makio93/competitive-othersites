#include <bits/stdc++.h>
using namespace std;

// 解説AC2

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length(), ri = n - 1;
        string t = s;
        for (int li=0; li<n; ++li) {
            if (isalpha(s[li])) {
                while (!isalpha(s[ri])) --ri;
                t[ri] = s[li];
                --ri;
            }
        }
        return t;
    }
};
