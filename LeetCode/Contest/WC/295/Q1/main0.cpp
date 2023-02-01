// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int n = s.length(), m = target.length();
        vector<int> ncnt(26), mcnt(26);
        for (int i=0; i<n; ++i) ncnt[s[i]-'a']++;
        for (int i=0; i<m; ++i) mcnt[target[i]-'a']++;
        int res = INF;
        for (int i=0; i<26; ++i) if (mcnt[i] > 0) res = min(res, ncnt[i]/mcnt[i]);
        return res;
    }
};
