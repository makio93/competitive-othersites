// 自力AC2-2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int id = 0;
        for (const char& ci : s) {
            if (ci == '*') --id;
            else {
                s[id] = ci;
                ++id;
            }
        }
        s.resize(id);
        return s;
    }
};
