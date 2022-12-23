// 学習1回目,解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        pair<int, int> mval = { 0, 0 };
        for (int i=0; i<n; ++i) {
            int li = i-1, ri = i+1;
            while (li>=0 && ri<n && s[li]==s[ri]) --li, ++ri;
            mval = max(mval, { ri-li-1, -(li+1) });
            li = i, ri = i+1;
            while (li>=0 && ri<n && s[li]==s[ri]) --li, ++ri;
            mval = max(mval, { ri-li-1, -(li+1) });
        }
        return s.substr(-mval.second, mval.first);
    }
};
