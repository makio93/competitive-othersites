// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length(), m = words.size();
        vector<vector<string::iterator>> wids(26);
        for (string& word : words) wids[*word.begin()-'a'].push_back(word.begin());
        int res = 0;
        for (const char& ci : s) {
            auto tmp = wids[ci-'a'];
            wids[ci-'a'].clear();
            for (auto& itr : tmp) {
                if (*next(itr) == '\0') ++res;
                else wids[*next(itr)-'a'].push_back(next(itr));
            }
        }
        return res;
    }
};
