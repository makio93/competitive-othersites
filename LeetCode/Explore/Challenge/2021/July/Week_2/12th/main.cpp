#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        map<char, char> change;
        set<char> used;
        bool res = true;
        for (int i=0; i<n; ++i) {
            if (change.find(s[i]) == change.end()) {
                if (used.find(t[i]) != used.end()) {
                    res = false;
                    break;
                }
                change[s[i]] = t[i];
                used.insert(t[i]);
            }
            else if (change[s[i]] != t[i]) {
                res = false;
                break;
            }
        }
        return res;
    }
};
