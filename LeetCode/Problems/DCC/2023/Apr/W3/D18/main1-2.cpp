// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        string res;
        res.reserve(n+m);
        for (int i=0; i<max(n,m); ++i) {
            if (i < n) res.push_back(word1[i]);
            if (i < m) res.push_back(word2[i]);
        }
        return res;
    }
};
