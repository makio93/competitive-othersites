#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        vector<int> cnt(n+1);
        for (int i=n-1; i>=0; --i) cnt[i] = (shifts[i] + cnt[i+1]) % 26;
        string res;
        for (int i=0; i<n; ++i) res.push_back((char)('a'+(s[i]-'a'+cnt[i])%26));
        return res;
    }
};
