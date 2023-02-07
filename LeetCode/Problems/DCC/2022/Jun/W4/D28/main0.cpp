// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> ccnt(26);
        for (char& ci : s) ccnt[ci-'a']++;
        sort(ccnt.rbegin(), ccnt.rend());
        int res = 0;
        for (int i=1; i<26; ++i) {
            if (ccnt[i] == 0) break;
            if (ccnt[i] < ccnt[i-1]) continue;
            int sub = ccnt[i] - max(0, ccnt[i-1]-1);
            res += sub;
            ccnt[i] -= sub;
        }
        return res;
    }
};
