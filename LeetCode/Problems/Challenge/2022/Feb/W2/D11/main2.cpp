#include <bits/stdc++.h>
using namespace std;

// 解説AC2

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        if (n < m) return false;
        vector<int> cnt1(26), cnt2(26);
        for (int i=0; i<m; ++i) cnt1[s1[i]-'a']++;
        for (int i=0; i<m; ++i) cnt2[s2[i]-'a']++;
        for (int i=0; i<n-m; ++i) {
            if (cnt1 == cnt2) return true;
            cnt2[s2[i+m]-'a']++;
            cnt2[s2[i]-'a']--;
        }
        return (cnt1 == cnt2);
    }
};
