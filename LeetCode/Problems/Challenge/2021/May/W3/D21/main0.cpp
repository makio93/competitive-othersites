#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size(), m = pattern.length();
        vector<string> res;
        vector<int> exist0(26, -1);
        int cnt0 = 0;
        for (char ci : pattern) {
            if (exist0[ci-'a'] == -1) {
                exist0[ci-'a'] = cnt0;
                ++cnt0;
            }
        }
        string tar;
        for (char ci : pattern) tar += (char)('a'+exist0[ci-'a']);
        for (int i=0; i<n; ++i) {
            vector<int> exist(26, -1);
            int cnt = 0;
            for (char ci : words[i]) {
                if (exist[ci-'a'] == -1) {
                    exist[ci-'a'] = cnt;
                    ++cnt;
                }
            }
            string edit;
            for (char ci : words[i]) edit += (char)('a'+exist[ci-'a']);
            if (edit == tar) res.push_back(words[i]);
        }
        return res;
    }
};
