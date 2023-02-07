// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        unordered_set<string> used(words.begin(), words.end());
        for (int i=0; i<n; ++i) {
            int len = words[i].length();
            for (int j=1; j<len; ++j) used.erase(words[i].substr(len-j));
        }
        int res = 0;
        for (const string& si : used) res += si.length() + 1;
        return res;
    }
};
