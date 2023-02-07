// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        if ((int)(t.length()) != n) return false;
        unordered_map<char, int> ccnt;
        for (int i=0; i<n; ++i) {
            ccnt[s[i]]++;
            ccnt[t[i]]--;
        }
        for (auto pi : ccnt) if (pi.second) return false;
        return true;
    }
};
