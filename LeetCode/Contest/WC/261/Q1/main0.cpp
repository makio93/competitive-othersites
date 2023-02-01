#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int minimumMoves(string s) {
        int n = s.length(), res = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == 'X') {
                ++res;
                i += 2;
            }
        }
        return res;
    }
};
