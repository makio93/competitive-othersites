// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        bool rev = false;
        if (n > m) {
            swap(n, m);
            swap(word1, word2);
            rev = true;
        }
        word1.resize(n+m);
        for (int i=n-1; i>=0; --i) {
            if (!rev) {
                word1[i*2+1] = word2[i];
                word1[i*2] = word1[i];
            }
            else {
                word1[i*2+1] = word1[i];
                word1[i*2] = word2[i];
            }
        }
        for (int i=n; i<m; ++i) word1[n*2+i-n] = word2[i];
        return word1;
    }
};
