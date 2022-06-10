// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<bool> cnt(128);
        int ri = 0, res = 0;
        for (int i=0; i<n; ++i) {
            while (ri<n && !cnt[(int)s[ri]]) {
                cnt[(int)s[ri]] = true;
                ++ri;
            }
            res = max(res, ri-i);
            cnt[(int)(s[i])] = false;
        }
        return res;
    }
};
