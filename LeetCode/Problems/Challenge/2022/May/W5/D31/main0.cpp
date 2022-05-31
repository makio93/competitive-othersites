// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if (n < k) return false;
        int val = 0;
        for (int i=0; i<k; ++i) {
            val *= 2;
            val += s[i] - '0';
        }
        unordered_set<int> st;
        st.insert(val);
        for (int i=0; i+k<n; ++i) {
            val -= ((s[i]-'0')<<(k-1));
            val *= 2;
            val += s[i+k] - '0';
            st.insert(val);
        }
        return (int)(st.size()) == (1<<k);
    }
};
