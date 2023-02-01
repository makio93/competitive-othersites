#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length(), tid = -1;
        for (int i=0; i<n; ++i) if (word[i] == ch) {
            tid = i;
            break;
        }
        if (tid != -1) reverse(word.begin(), word.begin()+tid+1);
        return word;
    }
};
