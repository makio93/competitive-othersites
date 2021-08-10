#include <bits/stdc++.h>
using namespace std;

// 自力AC2

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length(), ones = count(s.begin(), s.end(), '1');
        int zeros = 0, res = (n - ones);
        for (int i=0; i<n; ++i) {
            if (s[i] == '0') ++zeros;
            res = min(res, (i-zeros+1)*2+n-ones-i-1);
        }
        return res;
    }
};
