// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), m = words.size(), len = words.front().length();
        unordered_map<string, int> wlst;
        for (string& word : words) wlst[word]++;
        vector<int> res;
        for (int i=0; i<len; ++i) {
            unordered_map<string, int> tlst;
            int li = i, wcnt = 0;
            for (int ri=li+len; ri<=n; ri+=len) {
                string nword = s.substr(ri-len, len);
                if (wlst.find(nword) == wlst.end()) {
                    tlst.clear();
                    wcnt = 0;
                    li = ri;
                }
                else {
                    if (ri-li == m*len+len) {
                        string pword = s.substr(li, len);
                        tlst[pword]--;
                        if (tlst[pword] < wlst[pword]) --wcnt;
                        li += len;
                    }
                    tlst[nword]++;
                    if (tlst[nword] <= wlst[nword]) ++wcnt;
                    if (ri-li==m*len && wcnt==m) res.push_back(li);
                }
            }
        }
        return res;
    }
};
