// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        stack<char> st;
        for (int i=0; i<n; ++i) {
            if (s[i] == '*') { if (!st.empty()) st.pop(); }
            else st.push(s[i]);
        }
        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
