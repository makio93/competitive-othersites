// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), m = words.size(), len = words.front().length();
        vector<int> res;
        unordered_map<string, int> wlst;
        for (string& word : words) wlst[word]++;
        for (int i=0; i+m*len<=n; ++i) {
            auto tlst = wlst;
            int wcnt = 0;
            for (int j=i; j<i+m*len; j+=len) {
                string tstr = s.substr(j, len);
                if (tlst.find(tstr)!=tlst.end() && tlst[tstr]>0) {
                    tlst[tstr]--;
                    ++wcnt;
                }
                else break;
            }
            if (wcnt == m) res.push_back(i);
        }
        return res;
    }
};
