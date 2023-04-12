// 自力AC1-2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        string res;
        res.reserve(n);
        for (int i=0; i<n; ++i) {
            if (s[i] == '*') res.pop_back();
            else res.push_back(s[i]);
        }
        return res;
    }
};
