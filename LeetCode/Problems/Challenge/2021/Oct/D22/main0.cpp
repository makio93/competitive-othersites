#include <bits/stdc++.h>
using namespace std;

// 自力AC,Time:O(NlogN)

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ccnt;
        for (char ci : s) ccnt[ci]++;
        vector<pair<int, char>> clst;
        for (auto pi : ccnt) clst.emplace_back(pi.second, pi.first);
        sort(clst.rbegin(), clst.rend());
        string res;
        for (auto pi : clst) res += string(pi.first, pi.second);
        return res;
    }
};
