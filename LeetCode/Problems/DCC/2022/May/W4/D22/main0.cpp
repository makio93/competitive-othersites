// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int res = 0;
        for (int i=0; i<n; ++i) {
            ++res;
            for (int j=1; i-j>=0&&i+j<n; ++j) {
                if (s[i-j] != s[i+j]) break;
                ++res;
            }
            if (i+1 < n) {
                for (int j=0; i-j>=0&&i+j+1<n; ++j) {
                    if (s[i-j] != s[i+j+1]) break;
                    ++res;
                }
            }
        }
        return res;
    }
};
