// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), m = words.size(), len = words.front().length();
        vector<int> res;
        sort(words.begin(), words.end());
        for (int i=0; i+m*len-1<n; ++i) {
            vector<string> tmp;
            for (int j=i; j<i+m*len; j+=len) tmp.push_back(s.substr(j, len));
            sort(tmp.begin(), tmp.end());
            if (tmp == words) res.push_back(i);
        }
        return res;
    }
};
