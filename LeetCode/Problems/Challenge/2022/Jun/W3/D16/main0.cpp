// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        tuple<int, int, int> mval = { 0, -1, -1 };
        for (int i=0; i<n; ++i) {
            int li = i-1, ri = i+1, val = 1;
            while (li>=0 && ri<n && s[li]==s[ri]) val+=2, --li, ++ri;
            mval = max(mval, { val, li+1, ri-1 });
            if (i+1<n && s[i]==s[i+1]) {
                li = i-1, ri = i+2, val = 2;
                while (li>=0 && ri<n && s[li]==s[ri]) val+=2, --li, ++ri;
                mval = max(mval, { val, li+1, ri-1 });
            }
        }
        return s.substr(get<1>(mval), get<2>(mval)-get<1>(mval)+1);
    }
};
