// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> lids(n*2+1, n);
        int res = 0, val = n;
        for (int i=0; i<n; ++i) {
            if (s[i] == '(') {
                lids[val] = min(lids[val], i);
                ++val;
            }
            else {
                lids[val] = n;
                --val;
                if (lids[val] != n) res = max(res, i-lids[val]+1);
            }
        }
        return res;
    }
};
