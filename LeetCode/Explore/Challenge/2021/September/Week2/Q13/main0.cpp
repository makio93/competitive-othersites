#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    const string tar = "balloon";
public:
    int maxNumberOfBalloons(string text) {
        int n = text.length();
        vector<int> scnt(26), tcnt(26);
        for (int i=0; i<n; ++i) scnt[text[i]-'a']++;
        for (char ci : tar) tcnt[ci-'a']++;
        int res = n;
        for (int i=0; i<26; ++i) if (tcnt[i] > 0) res = min(res, scnt[i]/tcnt[i]);
        return res;
    }
};
