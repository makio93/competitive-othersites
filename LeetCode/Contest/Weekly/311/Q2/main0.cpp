// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length(), li = 0, res = 1;
        for (int i=0; i<n; ++i) {
            if (i+1>=n || s[i+1]!=(char)(s[i]+1)) {
                res = max(res, i-li+1);
                li = i + 1;
            }
        }
        return res;
    }
};
