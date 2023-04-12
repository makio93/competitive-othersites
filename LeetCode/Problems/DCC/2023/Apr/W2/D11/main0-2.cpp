// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int n = s.length(), id = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == '*') --id;
            else {
                s[id] = s[i];
                ++id;
            }
        }
        s.erase(s.begin()+id, s.end());
        return s;
    }
};
