// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for (char ci : s) if (ci == letter) ++cnt;
        return cnt * 100 / (int)(s.length());
    }
};
