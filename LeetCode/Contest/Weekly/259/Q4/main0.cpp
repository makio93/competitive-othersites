#include <bits/stdc++.h>
using namespace std;

// 本番,未完成

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();
        vector<int> ccnt(26);
        for (char ci : s) ccnt[ci-'a']++;
        unordered_set<char> clst;
        for (int i=0; i<26; ++i) if (ccnt[i] >= k) clst.insert((char)(i+'a'));
        string s;
        if (clst.empty()) return s;
        while (s.empty()) {
            int len = clst.size();

        }
    }
};
