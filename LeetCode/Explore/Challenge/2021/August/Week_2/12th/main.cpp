#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> strg;
        for (int i=0; i<n; ++i) {
            string tstr = strs[i];
            sort(tstr.begin(), tstr.end());
            strg[tstr].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto p : strg) res.push_back(p.second);
        return res;
    }
};
