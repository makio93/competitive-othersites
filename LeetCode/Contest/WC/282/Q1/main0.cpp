// バチャ本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size(), m = pref.length(), res = 0;
        for (int i=0; i<n; ++i) if (words[i].substr(0, m) == pref) ++res;
        return res;
    }
};
