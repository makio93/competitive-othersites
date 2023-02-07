#include <bits/stdc++.h>
using namespace std;

// 自力TLE

class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.length();
        pair<int, string> res = { 0, "" };
        unordered_set<string> slst;
        for (int i=n-1; i>=0; --i) for (int j=n; j>i; --j) {
            int rlen = j - i;
            if (slst.find(s.substr(i, rlen)) != slst.end()) res = max(res, { rlen, s.substr(i, rlen) });
            else slst.insert(s.substr(i, rlen));
            if (rlen <= res.first) break;
        }
        return res.second;
    }
};
