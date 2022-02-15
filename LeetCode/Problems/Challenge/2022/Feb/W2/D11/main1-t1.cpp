#include <bits/stdc++.h>
using namespace std;

// 解説での解法1,確率によりTLEする

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        unordered_map<char, int> cnt1;
        for (int i=0; i<m; ++i) cnt1[s1[i]]++;
        for (int i=0; i<n-m+1; ++i) {
            unordered_map<char, int> cnt2;
            for (int j=0; j<m; ++j) cnt2[s2[i+j]]++;
            if (cnt1 == cnt2) return true;
        }
        return false;
    }
};
