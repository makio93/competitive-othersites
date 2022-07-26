// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        vector<pair<char, int>> run;
        run.emplace_back('1', 1);
        for (int i=1; i<n; ++i) {
            if (run.back().first == s[i]) run.back().second++;
            else run.emplace_back(s[i], 1);
        }
        return ((int)(run.size()) <= 2);
    }
};
