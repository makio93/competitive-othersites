#include <bits/stdc++.h>
using namespace std;

// 自力TLE

using ll = long long;
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> res;
        unordered_map<string, set<pair<int, int>>> lid;
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            lid[words[i]+words[j]].emplace(i, j);
            lid[words[j]+words[i]].emplace(j, i);
        }
        auto rwords = words;
        for (int i=0; i<n; ++i) reverse(rwords[i].begin(), rwords[i].end());
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            if (lid.find(rwords[i]+rwords[j])!=lid.end() && lid[rwords[i]+rwords[j]].find({j, i})!=lid[rwords[i]+rwords[j]].end()) {
                res.push_back({j, i});
            }
            if (lid.find(rwords[j]+rwords[i])!=lid.end() && lid[rwords[j]+rwords[i]].find({i, j})!=lid[rwords[j]+rwords[i]].end()) {
                res.push_back({i, j});
            }
        }
        return res;
    }
};
