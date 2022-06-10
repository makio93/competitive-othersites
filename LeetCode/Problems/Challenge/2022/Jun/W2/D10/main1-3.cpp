// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int li = 0, ri = 0, res = 0;
        vector<int> ccnt(128, -1);
        while (li<n && ri<n) {
            if (ccnt[(int)s[ri]] != -1) li = max(li, ccnt[s[ri]]);
            ccnt[s[ri]] = ri+1;
            res = max(res, ri-li+1);
            ++ri;
        }
        return res;
    }
};
