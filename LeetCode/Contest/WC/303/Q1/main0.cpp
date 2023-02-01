// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> ccnt(26);
        char res = 0;
        for (char ci : s) {
            if (ccnt[ci-'a'] > 0) {
                res = ci;
                break;
            }
            ccnt[ci-'a']++;
        }
        return res;
    }
};
