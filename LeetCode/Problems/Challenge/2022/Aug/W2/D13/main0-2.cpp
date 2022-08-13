// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), m = words.size(), len = words.front().length();
        vector<int> res;
        unordered_map<string, int> wcnt;
        for (int i=0; i<m; ++i) wcnt[words[i]]++;
        for (int i=0; i+m*len-1<n; ++i) {
            unordered_map<string, int> tcnt;
            for (int j=i; j<i+m*len; j+=len) tcnt[s.substr(j, len)]++;
            if (tcnt == wcnt) res.push_back(i);
        }
        return res;
    }
};
