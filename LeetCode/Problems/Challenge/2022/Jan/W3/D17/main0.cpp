#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.length(), slen = s.length();
        vector<string> words;
        int lid = 0;
        for (int i=0; i<slen; ++i) if (s[i] == ' ') {
            words.push_back(s.substr(lid, i-lid));
            lid = i + 1;
        }
        words.push_back(s.substr(lid, slen-lid));
        unordered_map<char, string> cs;
        int m = words.size();
        if (n != m) return false;
        for (int i=0; i<n; ++i) {
            if (cs.find(pattern[i]) == cs.end()) cs[pattern[i]] = words[i];
            else if (cs[pattern[i]] != words[i]) return false;
        }
        unordered_set<string> wcnt;
        for (auto pi : cs) wcnt.insert(pi.second);
        return ((int)(wcnt.size()) == (int)(cs.size()));
    }
};
