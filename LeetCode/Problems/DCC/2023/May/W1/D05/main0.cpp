// 自力AC

#include <bits/stdc++.h>
using namespace std;

const string vowels = "aeiou";
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length(), cnt = 0, res = 0;
        for (int i=0; i<k-1; ++i) if (find(vowels.begin(), vowels.end(), s[i]) != vowels.end()) ++cnt;
        for (int i=k-1; i<n; ++i) {
            if (find(vowels.begin(), vowels.end(), s[i]) != vowels.end()) ++cnt;
            res = max(res, cnt);
            if (find(vowels.begin(), vowels.end(), s[i-k+1]) != vowels.end()) --cnt;
        }
        return res;
    }
};
