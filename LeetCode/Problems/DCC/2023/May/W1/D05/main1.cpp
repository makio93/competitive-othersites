// 解説AC

#include <bits/stdc++.h>
using namespace std;

static const unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length(), cnt = 0;
        for (int i=0; i<k; ++i) if (vowels.find(s[i]) != vowels.end()) ++cnt;
        int res = cnt;
        for (int i=k; i<n; ++i) {
            cnt += (vowels.find(s[i]) != vowels.end()) - (vowels.find(s[i-k]) != vowels.end());
            res = max(res, cnt);
        }
        return res;
    }
};
