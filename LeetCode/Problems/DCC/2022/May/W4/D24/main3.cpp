// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int res = 0, li = 0, ri = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == '(') ++li;
            else ++ri;
            if (li == ri) res = max(res, li+ri);
            else if (ri > li) li = ri = 0;
        }
        li = ri = 0;
        for (int i=n-1; i>=0; --i) {
            if (s[i] == ')') ++ri;
            else ++li;
            if (li == ri) res = max(res, li+ri);
            else if (li > ri) li = ri = 0;
        }
        return res;
    }
};
