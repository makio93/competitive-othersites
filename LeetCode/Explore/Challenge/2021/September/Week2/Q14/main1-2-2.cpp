#include <bits/stdc++.h>
using namespace std;

// 解説AC2,改良版

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length(), ri = n - 1;
        for (int li=0; li<ri; ++li) {
            if (isalpha(s[li])) {
                while (!isalpha(s[ri])) --ri;
                if (li >= ri) break;
                int tc = s[li]; s[li] = s[ri]; s[ri] = tc;
                --ri;
            }
        }
        return s;
    }
};
