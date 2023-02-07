#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string res;
        for (int i=0; i<n; ++i) {
            res.push_back(s[i]);
            while (res.length()>=2 && res[res.length()-2]==res[res.length()-1]) { res.pop_back(); res.pop_back(); }
        }
        return res;
    }
};
