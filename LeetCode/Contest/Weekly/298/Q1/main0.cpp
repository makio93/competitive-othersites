// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> lower(26), upper(26);
        for (char ci : s) {
            if (islower(ci)) lower[ci-'a'] = true;
            else upper[ci-'A'] = true;
        }
        int mval = -1;
        for (int i=0; i<26; ++i) if (lower[i] && upper[i]) mval = i;
        string res = "";
        if (mval != -1) res += (char)(mval+'A');
        return res;
    }
};
