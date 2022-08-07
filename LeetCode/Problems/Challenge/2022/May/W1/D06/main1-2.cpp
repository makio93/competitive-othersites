// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        vector<pair<char, int>> runs(1, { '#', 0 });
        for (char& ci : s) {
            if (runs.back().first != ci) runs.emplace_back(ci, 1);
            else {
                runs.back().second++;
                if (runs.back().second == k) runs.pop_back();
            }
        }
        string res;
        for (auto& pi : runs) res.append(pi.second, pi.first);
        return res;
    }
};
