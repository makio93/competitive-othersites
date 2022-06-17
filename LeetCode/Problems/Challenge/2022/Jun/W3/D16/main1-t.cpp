// 解説1-t,TLE解

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        pair<int, int> mval = { 0, -1 };
        auto is_palind = [&](int li, int ri) -> bool {
            while (ri > li) {
                if (s[li] != s[ri]) return false;
                ++li, --ri;
            }
            return true;
        };
        for (int i=0; i<n; ++i) for (int j=i; j<n; ++j) 
            if (is_palind(i, j)) mval = max(mval, { j-i+1, -i });
        return s.substr(-mval.second, mval.first);
    }
};
