// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        unordered_set<string> st(words.begin(), words.end());
        for (string& si : words) {
            int m = si.length();
            for (int i=1; i<m; ++i) st.erase(si.substr(i));
        }
        int res = 0;
        for (string si : st) res += si.length() + 1;
        return res;
    }
};
