// バチャ本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int m = s.length(), n = t.length(), res = 0;
        vector<int> ccnt(26);
        for (int i=0; i<m; ++i) ccnt[s[i]-'a']++;
        for (int i=0; i<n; ++i) ccnt[t[i]-'a']--;
        for (int i=0; i<26; ++i) res += abs(ccnt[i]);
        return res;
    }
};
