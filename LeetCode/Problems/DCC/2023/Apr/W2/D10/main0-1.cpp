// 自力AC1

#include <bits/stdc++.h>
using namespace std;

const string op = "({[", cl = ")}]";
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for (int i=0; i<n; ++i) {
            if (op.find(s[i]) < 3) st.push(s[i]);
            else {
                if (st.empty() || op.find(st.top())!=cl.find(s[i])) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
