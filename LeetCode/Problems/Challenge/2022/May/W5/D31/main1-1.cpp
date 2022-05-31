// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_set<string> st;
        for (int i=0; i+k-1<n; ++i) st.insert(s.substr(i, k));
        return (int)(st.size()) == (1<<k);
    }
};
