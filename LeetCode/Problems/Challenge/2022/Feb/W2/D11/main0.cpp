#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<int> cnt1(26), cnt2(26);
        for (char ci : s1) cnt1[ci-'a']++;
        for (int i=0; i<n; ++i) {
            cnt2[s2[i]-'a']++;
            if (i-m >= 0) cnt2[s2[i-m]-'a']--;
            if (i>=m-1 && cnt1==cnt2) return true;
        }
        return false;
    }
};
