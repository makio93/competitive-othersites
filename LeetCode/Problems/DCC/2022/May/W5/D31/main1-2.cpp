// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        vector<bool> used(1<<k);
        int val = 0, cnt = 0;
        for (int i=0; i<n; ++i) {
            val = (val << 1) & ((1<<k) - 1) | (s[i] - '0');
            if (i>=k-1 && !used[val]) {
                used[val] = true;
                ++cnt;
            }
        }
        return (cnt == (1<<k));
    }
};
