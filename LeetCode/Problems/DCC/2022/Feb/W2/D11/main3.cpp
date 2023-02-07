#include <bits/stdc++.h>
using namespace std;

// 解説AC3

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        if (n < m) return false;
        vector<int> cnt1(26), cnt2(26);
        for (int i=0; i<m; ++i) cnt1[s1[i]-'a']++;
        for (int i=0; i<m; ++i) cnt2[s2[i]-'a']++;
        int ccnt = 0;
        for (int i=0; i<26; ++i) if (cnt1[i] == cnt2[i]) ++ccnt;
        for (int i=0; i<n-m; ++i) {
            if (ccnt == 26) return true;
            int lch = s2[i] - 'a', rch = s2[i+m] - 'a';
            cnt2[rch]++;
            if (cnt1[rch] == cnt2[rch]) ++ccnt;
            else if (cnt1[rch] == cnt2[rch]-1) --ccnt;
            cnt2[lch]--;
            if (cnt1[lch] == cnt2[lch]) ++ccnt;
            else if (cnt1[lch] == cnt2[lch]+1) --ccnt;
        }
        return (ccnt == 26);
    }
};
