// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int n = s.length(), res = 1;
        vector<bool> ccnt(26);
        for (int i=0; i<n; ++i) {
            if (ccnt[s[i]-'a']) {
                ccnt.assign(26, false);
                ++res;
            }
            ccnt[s[i]-'a'] = true;
        }
        return res;
    }
};
