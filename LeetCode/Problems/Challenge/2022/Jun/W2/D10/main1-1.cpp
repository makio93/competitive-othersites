// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int li = 0, ri = 0, res = 0;
        vector<int> ccnt(128);
        while (li<n && ri<n) {
            ccnt[(int)s[ri]]++;
            while (ccnt[(int)(s[ri])] > 1) {
                ccnt[(int)s[li]]--;
                ++li;
            }
            res = max(res, ri-li+1);
            ++ri;
        }
        return res;
    }
};
