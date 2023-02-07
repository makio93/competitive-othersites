// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> ccnt(26);
        for (char& ci : s) ccnt[ci-'a']++;
        for (char& ci : t) {
            if (ccnt[ci-'a'] == 0) return false;
            ccnt[ci-'a']--;
        }
        return true;
    }
};
