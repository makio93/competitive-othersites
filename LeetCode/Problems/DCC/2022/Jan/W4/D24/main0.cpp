#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        if (n == 1) return true;
        if (islower(word[0]) == islower(word[1])) {
            for (int i=2; i<n; ++i) if (islower(word[0]) != islower(word[i])) return false;
            return true;
        }
        else {
            if (!isupper(word[0])) return false;
            for (int i=1; i<n; ++i) if (!islower(word[i])) return false;
            return true;
        }
    }
};
