#include <bits/stdc++.h>
using namespace std;

// 自力AC,解法1

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> scnt(26), tcnt(26);
        for (char ci : s) scnt[ci-'a']++;
        for (char ci : t) tcnt[ci-'a']++;
        char res = (char)0;
        for (int i=0; i<26; ++i) if (tcnt[i] == scnt[i]+1) {
            res = (char)('a' + i);
            break;
        }
        return res;
    }
};
