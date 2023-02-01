#include <bits/stdc++.h>
using namespace std;

// バチャ本番AC

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size(), res = 0;
        unordered_map<string, int> wcnt;
        for (int i=0; i<n; ++i) wcnt[words[i]]++;
        for (char a='a'; a<'z'; ++a) for (char b=a+1; b<='z'; ++b) {
            string s1 = { a, b }, s2 = { b, a };
            if (wcnt.find(s1)==wcnt.end() || wcnt.find(s2)==wcnt.end()) continue;
            res += min(wcnt[s1], wcnt[s2]) * 4;
        }
        bool odd = false;
        for (char a='a'; a<='z'; ++a) if (wcnt.find(string({a,a})) != wcnt.end()) {
            res += wcnt[string({a,a})] / 2 * 2 * 2;
            if (wcnt[string({a,a})]%2==1 && !odd) {
                res += 2;
                odd = true;
            }
        }
        return res;
    }
};
