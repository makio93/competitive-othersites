#include <bits/stdc++.h>
using namespace std;

// 解説AC1

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<int> cnt1(26);
        for (int i=0; i<m; ++i) cnt1[s1[i]-'a']++;
        for (int i=0; i<n-m+1; ++i) {
            vector<int> cnt2(26);
            for (int j=0; j<m; ++j) cnt2[s2[i+j]-'a']++;
            if (cnt1 == cnt2) return true;
        }
        return false;
    }
};
