// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        vector<int> ccnt(26);
        for (char& ci : s) ccnt[ci-'a']++;
        sort(ccnt.begin(), ccnt.end(), greater<int>());
        int res = 0, mval = n;
        for (int i=0; i<26; ++i) {
            if (ccnt[i] == 0) break;
            if (ccnt[i] > mval) {
                res += ccnt[i] - mval;
                ccnt[i] = mval;
            }
            mval = max(0, ccnt[i]-1);
        }
        return res;
    }
};
