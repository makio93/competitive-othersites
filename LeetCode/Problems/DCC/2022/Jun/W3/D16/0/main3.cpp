// 解説AC3,for文

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        pair<int, int> mval = { 0, -1 };
        auto search = [&](int li, int ri) -> int {
            while (li>=0 && ri<n && s[li]==s[ri]) --li, ++ri;
            return ri - li - 1;
        };
        for (int i=0; i<n; ++i) {
            int len = max(search(i, i), search(i, i+1));
            mval = max(mval, { len, -(i-(len-1)/2) });
        }
        return s.substr(-mval.second, mval.first);
    }
};
