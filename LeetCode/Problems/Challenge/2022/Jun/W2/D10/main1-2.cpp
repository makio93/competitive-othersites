// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int li = 0, ri = 0, res = 0;
        unordered_map<char, int> ccnt;
        while (li<n && ri<n) {
            if (ccnt.find(s[ri]) != ccnt.end()) li = max(li, ccnt[s[ri]]);
            ccnt[s[ri]] = ri+1;
            res = max(res, ri-li+1);
            ++ri;
        }
        return res;
    }
};
