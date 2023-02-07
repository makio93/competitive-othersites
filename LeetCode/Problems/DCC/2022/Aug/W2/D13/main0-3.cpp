// 自力AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), m = words.size(), len = words.front().length();
        vector<int> res;
        unordered_map<string, int> wcnt;
        for (int i=0; i<m; ++i) wcnt[words[i]]++;
        for (int i1=0; i1<len&&i1+m*len<=n; ++i1) {
            unordered_map<string, int> tcnt;
            for (int i=i1; i<i1+m*len; i+=len) tcnt[s.substr(i, len)]++;
            if (tcnt == wcnt) res.push_back(i1);
            for (int i=i1+len; i+m*len<=n; i+=len) {
                tcnt[s.substr(i-len, len)]--;
                if (tcnt[s.substr(i-len, len)] == 0) tcnt.erase(s.substr(i-len, len));
                tcnt[s.substr(i+(m-1)*len, len)]++;
                if (tcnt == wcnt) res.push_back(i);
            }
        }
        return res;
    }
};
