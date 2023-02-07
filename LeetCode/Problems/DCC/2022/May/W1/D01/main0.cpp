// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1, str2;
        for (char& ci : s) {
            if (ci == '#') { if (!str1.empty()) str1.pop_back(); }
            else str1.push_back(ci);
        }
        for (char& ci : t) {
            if (ci == '#') { if (!str2.empty()) str2.pop_back(); }
            else str2.push_back(ci);
        }
        return str1 == str2;
    }
};
