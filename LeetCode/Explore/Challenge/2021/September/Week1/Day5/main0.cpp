#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.length();
        string res = s;
        if (k == 1) for (int i=0; i<n; ++i) res = min(res, s.substr(i)+s.substr(0, i));
        else sort(res.begin(), res.end());
        return res;
    }
};
