// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    string build(string str) {
        string res;
        for (char& ci : str) {
            if (ci != '#') res.push_back(ci);
            else if (!res.empty()) res.pop_back();
        }
        return res;
    }
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};
