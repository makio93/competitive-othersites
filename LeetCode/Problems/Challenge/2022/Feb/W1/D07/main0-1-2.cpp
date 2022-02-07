#include <bits/stdc++.h>
using namespace std;

// 自力AC,解法1,少し手直し

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> scnt(26), tcnt(26);
        for (char ci : s) scnt[ci-'a']++;
        for (char ci : t) tcnt[ci-'a']++;
        for (int i=0; i<26; ++i) if (tcnt[i] == scnt[i]+1) return (char)('a' + i);
        return (char)0;
    }
};
