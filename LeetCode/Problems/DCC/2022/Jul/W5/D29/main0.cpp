// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size(), m = pattern.length();
        vector<string> res;
        for (string& word : words) {
            unordered_map<char, char> plst;
            bool ok = true;
            for (int i=0; i<m; ++i) {
                if (plst.find(pattern[i]) == plst.end()) plst[pattern[i]] = word[i];
                else if (plst[pattern[i]] != word[i]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            unordered_set<char> ccnt;
            for (auto& pi : plst) ccnt.insert(pi.second);
            if (plst.size() != ccnt.size()) continue;
            res.push_back(word);
        }
        return res;
    }
};
