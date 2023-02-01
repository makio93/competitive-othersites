#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    string largestMerge(string word1, string word2) {
        if (word1.empty() || word2.empty()) return word1 + word2;
        else if (word1 >= word2) return string("") + word1.front() + largestMerge(word1.substr(1), word2);
        else return string("") + word2.front() + largestMerge(word1, word2.substr(1));
    }
};
