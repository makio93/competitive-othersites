#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> ccnt1(26), ccnt2(26);
        for (int i=0; i<n; ++i) ccnt1[word1[i]-'a']++;
        for (int i=0; i<m; ++i) ccnt2[word2[i]-'a']++;
        bool res = true;
        for (int i=0; i<26; ++i) if (abs(ccnt1[i]-ccnt2[i]) > 3) res = false;
        return res;
    }
};
