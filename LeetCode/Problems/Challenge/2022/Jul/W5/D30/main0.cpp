// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> ccnt(26);
        for (auto& word : words2) {
            vector<int> tcnt(26);
            for (char& ci : word) tcnt[ci-'a']++;
            for (int i=0; i<26; ++i) ccnt[i] = max(ccnt[i], tcnt[i]);
        }
        vector<string> res;
        for (auto& word : words1) {
            vector<int> tcnt(26);
            for (char& ci : word) tcnt[ci-'a']++;
            bool ok = true;
            for (int i=0; i<26; ++i) if (tcnt[i] < ccnt[i]) {
                ok = false;
                break;
            }
            if (ok) res.push_back(word);
        }
        return res;
    }
};
