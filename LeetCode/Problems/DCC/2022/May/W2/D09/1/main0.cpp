// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<string> tar = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> res, nlst;
        if (n == 0) return res;
        res.push_back("");
        for (int i=0; i<n; ++i) {
            nlst.clear();
            for (const string& si : res) for (const char& ci : tar[digits[i]-'2']) nlst.push_back(si+ci);
            res.swap(nlst);
        }
        return res;
    }
};
