// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        vector<pair<char, int>> runs;
        for (char& ci : s) {
            if (runs.empty() || runs.back().first!=ci) runs.emplace_back(ci, 1);
            else {
                runs.back().second++;
                if (runs.back().second >= k) {
                    runs.back().second -= k;
                    if (runs.back().second == 0) runs.pop_back();
                }
            }
        }
        string res;
        for (auto& pi : runs) res += string(pi.second, pi.first);
        return res;
    }
};
