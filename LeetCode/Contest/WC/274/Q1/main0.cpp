#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        vector<pair<char, int>> ccnt;
        ccnt.emplace_back('a', 0);
        for (int i=0; i<n; ++i) {
            if (s[i] == ccnt.back().first) ccnt.back().second++;
            else if (s[i] == 'b') ccnt.emplace_back('b', 1);
            else return false;
        }
        return true;
    }
};
