#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n = words.size();
        string t;
        for (int i=0; i<n; ++i) {
            t += words[i];
            if (t.length() == s.length()) return (s == t);
            else if (t.length() > s.length()) return false;
        }
        return false;
    }
};
