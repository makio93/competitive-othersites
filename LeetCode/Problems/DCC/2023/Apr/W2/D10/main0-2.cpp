// 自力AC2

#include <bits/stdc++.h>
using namespace std;

unordered_map<char, char> brs = { { '(', ')' }, { '{', '}' }, { '[', ']' } };
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for (int i=0; i<n; ++i) {
            if (brs.find(s[i]) != brs.end()) st.push(s[i]);
            else {
                if (st.empty() || brs[st.top()]!=s[i]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
