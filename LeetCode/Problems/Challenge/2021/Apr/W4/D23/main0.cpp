#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length(), res = 0;
        vector<pair<char, int>> runs;
        runs.emplace_back(s[0], 1);
        for (int i=1; i<n; ++i) {
            if (s[i] == runs.back().first) runs.back().second++;
            else runs.emplace_back(s[i], 1);
        }
        int m = runs.size();
        for (int i=0; i<m-1; ++i) res += min(runs[i].second, runs[i+1].second);
        return res;
    }
};
