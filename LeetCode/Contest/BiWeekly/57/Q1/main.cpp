#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char, int> cnt;
        for (char c : s) cnt[c]++;
        bool ok = true;
        int val = cnt.begin()->second;
        for (auto p : cnt) if (p.second != val) ok = false;
        return ok;
    }
};